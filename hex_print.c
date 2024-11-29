/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:54:17 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 16:59:16 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_value(t_format *obj, size_t num, char **num_str, char **hash)
{
	char	hex_a;
	char	c;

	c = set_or_get_hex_case('\0', 1);
	if (c == 'x')
		hex_a = 'a' - 10;
	else if (c == 'X')
		hex_a = 'A' - 10;
	else
		hex_a = '\0';
	if (num && obj->flag_hash)
		set_hash_str(hash, c);
	else
		*hash = ft_strdup_new("");
	if (!num && !obj->precision[1])
	{
		*num_str = ft_strdup_new("0");
		return ;
	}
	*num_str = unsigned_hex_itoa(num, hex_a);
}

static void	set_precision(t_format *obj, size_t num, char **str, char **hash)
{
	char	*zero_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(*str);
	i = ft_strlen(*hash);
	if ((size_t)obj->precision[1] > len)
		len = obj->precision[1] - len;
	else
		len = 0;
	zero_str = ft_calloc(len + 1, 1);
	if (!zero_str)
	{
		check_errors(1, 0);
		return ;
	}
	i = 0;
	while (i < len)
		*(zero_str + i++) = '0';
	dealloc_str_and_set_new(hash, ft_strjoin_new(*hash, zero_str));
	if (!num && !obj->precision[1])
		dealloc_str_and_set_new(str, ft_strdup_new(""));
	dealloc_str_and_set_new(str, ft_strjoin_new(*hash, *str));
	free(zero_str);
}

static void	set_num_no_dot(t_format *obj, size_t num, char **str, char **hash)
{
	char	*zero_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(*str);
	i = ft_strlen(*hash);
	if ((size_t)obj->width[1] > len)
		len = obj->width[1] - len;
	else
		len = 0;
	zero_str = ft_calloc(len + 1, 1);
	if (!zero_str)
		return ;
	if (i && len >= i)
		len -= i;
	else
		len = 0;
	i = 0;
	while (i < len)
		*(zero_str + i++) = '0';
	dealloc_str_and_set_new(hash, ft_strjoin_new(*hash, zero_str));
	if (!num && !obj->width[1])
		dealloc_str_and_set_new(str, ft_strdup_new(""));
	dealloc_str_and_set_new(str, ft_strjoin_new(*hash, *str));
	free(zero_str);
}

static void	handle_flag(char **str, size_t *num, t_format *obj, char **hash)
{
	if (obj->flag_dot)
		obj->flag_zero = 0;
	if (!*num)
		obj->flag_hash = 0;
	set_value(obj, *num, str, hash);
	if (!str)
		return ;
	if (!obj->flag_dot)
	{
		if (obj->flag_zero && obj->flag_hash && obj->width[1])
			set_num_no_dot(obj, *num, str, hash);
		else
			dealloc_str_and_set_new(str, ft_strjoin_new(*hash, *str));
	}
	else
		set_precision(obj, *num, str, hash);
	free(*hash);
	*hash = NULL;
}

void	print_hex(int *obj_len, int print_need, t_format *obj)
{
	static char		*num_str;
	static char		*hash;
	static int		need_free_mem;
	size_t			num;

	if (!num_str)
	{
		num = va_arg(*obj->data, unsigned int);
		handle_flag(&num_str, &num, obj, &hash);
		if (!num_str)
			return ;
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
