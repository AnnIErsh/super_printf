/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:10:11 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 19:13:44 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_sign(char sign, char **str)
{
	if (sign == '+')
		*str = ft_strdup_new("+");
	else if (sign == '-')
		*str = ft_strdup_new("-");
	else
		*str = ft_strdup_new(" ");
}

void	print_with_length(size_t len, char c)
{
	while (len)
	{
		ft_putchar_with_count(c);
		len--;
	}
}

void	dealloc_str_and_set_new(char **str, char *new_str)
{
	char	*old;

	if (!str)
		return ;
	old = *str;
	if (new_str)
	{
		*str = new_str;
		free(old);
	}
}

char	set_or_get_hex_case(char c, int get)
{
	static char	x;

	if (get)
		return (x);
	x = c;
	return ('\0');
}

void	set_hash_str(char **hash_str, char c)
{
	if (!hash_str)
		return ;
	if (c == 'x')
		*hash_str = ft_strdup_new("0x");
	if (c == 'X')
		*hash_str = ft_strdup_new("0X");
}
