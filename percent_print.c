/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:06:11 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/22 23:06:36 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(int *obj_len, int print_need, t_format *obj)
{
	if (print_need)
	{
		if (obj->width[0])
			va_arg(*obj->data, int);
		ft_putchar_with_count('%');
	}
	*obj_len = 1;
}
