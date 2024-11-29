/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:02:10 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/24 13:45:46 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(int *obj_len, int print_need, t_format *obj)
{
	static char	*str;
	static int	need_free_mem;

	if (!str)
		str = va_arg(*obj->data, char *);
	if (!str)
		str = "(null)";
	*obj_len = (int)ft_strlen(str);
	if (*obj_len < 0)
		*obj_len = 0;
	if (obj->flag_dot && obj->precision[1] < *obj_len)
	{
		str = ft_substr(str, 0, obj->precision[1]);
		need_free_mem = 1;
		*obj_len = (int)ft_strlen(str);
	}
	if (print_need)
	{
		ft_putstr_with_count(str);
		if (need_free_mem)
			free(str);
		need_free_mem = 0;
		str = NULL;
	}
}
