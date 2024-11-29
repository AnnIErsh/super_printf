/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:18:31 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 16:52:24 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_value(t_format *obj, unsigned int num, char **num_str)
{
	if (!num && !obj->precision[1])
	{
		*num_str = ft_strdup_new("0");
		return ;
	}
	*num_str = unsigned_itoa(num);
}

static void	handle_flag(char **str, unsigned int *num, t_format *obj)
{
	if (obj->flag_dot)
		obj->flag_zero = 0;
	set_value(obj, *num, str);
}

static void	set_num_precision(t_format *obj, unsigned int num, char **str)
{
	char	*zero_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(*str);
	i = 0;
	if ((size_t)obj->precision[1] > len)
		len = obj->precision[1] - len;
	else
		len = i;
	zero_str = ft_calloc(len + 1, 1);
	if (!zero_str)
		return ;
	while (i < len)
		*(zero_str + i++) = '0';
	if (!num && !obj->precision[1])
		dealloc_str_and_set_new(str, ft_strdup_new(""));
	dealloc_str_and_set_new(str, ft_strjoin_new(zero_str, *str));
	free(zero_str);
}

void	print_unsigned(int *obj_len, int print_need, t_format *obj)
{
	static char		*num_str;
	static int		need_free_mem;
	unsigned int	num;

	if (!num_str)
	{
		num = va_arg(*obj->data, unsigned int);
		handle_flag(&num_str, &num, obj);
		if (!num_str)
			return ;
		if (obj->flag_dot)
			set_num_precision(obj, num, &num_str);
		need_free_mem = 1;
		*obj_len = ft_strlen(num_str);
		if (*obj_len < 0)
			*obj_len = 0;
	}
	if (print_need)
	{
		ft_putstr_with_count(num_str);
		if (need_free_mem)
			free(num_str);
		need_free_mem = 0;
		num_str = NULL;
	}
}
