/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:05:13 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/22 23:05:42 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int *obj_len, int print_need, t_format *obj)
{
	int	res;

	res = '\0';
	if (print_need)
	{
		res = va_arg(*obj->data, int);
		ft_putchar_with_count(res);
	}
	*obj_len = 1;
}
