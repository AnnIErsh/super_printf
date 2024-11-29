/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:00:49 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 17:57:30 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_sign_and_set_abs_val(t_format *obj, long num, char **num_str)
{
	if (!num && !obj->precision[1])
	{
		*num_str = ft_strdup_new("0");
		if (obj->flag_plus)
			return ('+');
		else if (obj->flag_space)
			return (' ');
		return (0);
	}
	if (num < 0)
	{
		num *= -1;
		if (num == 2147483648)
			*num_str = ft_strdup_new("2147483648");
		else
			*num_str = ft_itoa_new(num);
		return ('-');
	}
	*num_str = ft_itoa_new(num);
	if (obj->flag_plus)
		return ('+');
	else if (obj->flag_space)
		return (' ');
	return (0);
}

static void	set_no_dot_situation(t_format *obj, int sign, char **str, long num)
{
	char	*tmp;

	if (obj->flag_zero && sign)
	{
		ft_putchar_with_count(sign);
		obj->width[1] -= 1;
		return ;
	}
	if (!obj->flag_dot)
	{
		if (sign == '+' && num == 2147483648)
		{
			free(*str);
			*str = ft_strdup_new("+2147483648");
			return ;
		}
		if (sign)
		{
			set_sign(sign, &tmp);
			dealloc_str_and_set_new(str, ft_strjoin_new(tmp, *str));
			free(tmp);
		}
	}
}

static void	set_num_precision(t_format *obj, long num, char **str, int sign)
{
	char	*zero_str;
	int		len;
	int		i;

	len = ft_strlen(*str);
	i = 0;
	if (sign)
		i++;
	if (obj->precision[1] > len)
		len = obj->precision[1] - len + i;
	else
		len = i;
	zero_str = ft_calloc(len + 1, 1);
	if (!zero_str)
		return ;
	*zero_str = sign;
	while (i < len)
		*(zero_str + i++) = '0';
	if (!num && !obj->precision[1])
		dealloc_str_and_set_new(str, ft_strdup_new(""));
	dealloc_str_and_set_new(str, ft_strjoin_new(zero_str, *str));
	free(zero_str);
}

static void	handle_flag_and_sign(char **str, int *num, int *sign, t_format *obj)
{
	if (obj->flag_dot)
		obj->flag_zero = 0;
	if (obj->flag_plus)
		obj->flag_space = 0;
	*sign = get_sign_and_set_abs_val(obj, *num, str);
	if (!str)
		return ;
	set_no_dot_situation(obj, *sign, str, *num);
}

void	print_int(int *obj_len, int print_need, t_format *obj)
{
	static char	*num_str;
	static int	need_free_mem;
	static int	sign;
	int			num;

	if (!num_str)
	{
		num = va_arg(*obj->data, int);
		handle_flag_and_sign(&num_str, &num, &sign, obj);
		if (obj->flag_dot)
			set_num_precision(obj, num, &num_str, sign);
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
		sign = 0;
		num_str = NULL;
	}
}
