/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:20:37 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 19:18:47 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(int *obj_len, int print_need, t_format *obj)
{
	static char		*str;
	static int		need_free_mem;
	unsigned long	num;

	if (!str)
	{
		num = (unsigned long)va_arg(*obj->data, void *);
		str = unsigned_hex_itoa(num, 'a' - 10);
		dealloc_str_and_set_new(&str, ft_strjoin_new("0x", str));
		if (!str || !*str)
			return ;
		need_free_mem = 1;
		*obj_len = ft_strlen(str);
		if (*obj_len < 0)
			*obj_len = 0;
	}
	if (print_need && str)
	{
		ft_putstr_with_count(str);
		if (need_free_mem)
			free(str);
		need_free_mem = 0;
		str = NULL;
	}
}
