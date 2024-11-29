/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:28:42 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/26 17:36:11 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*alloc_check(int size, int sign)
{
	char	*str;

	str = malloc(size + 1 + sign);
	if (!str)
	{
		check_errors(1, 0);
		return (NULL);
	}
	return (str);
}
