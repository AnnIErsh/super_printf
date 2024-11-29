/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:27:54 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 16:14:36 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create_number_hex(char *str, size_t len, size_t n, char hex_a)
{
	static size_t	i;
	size_t			res;

	if (i < len && str + i && n)
	{
		res = n % 16;
		n /= 16;
		if (res >= 10)
			*(str + i) = res + hex_a;
		else
			*(str + i) = res + '0';
		i++;
		create_number_hex(str, len, n, hex_a);
	}
	else
		i = 0;
}

static size_t	calculate_size_hex(size_t n, size_t i)
{
	if (n)
	{
		n /= 16;
		i++;
		return (calculate_size_hex(n, i));
	}
	return (i);
}

static void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	revert_string(char *str, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		swap(str + i, str + j);
		i++;
		j--;
	}
}

char	*unsigned_hex_itoa(size_t n, char hex_a)
{
	size_t	num;
	size_t	size;
	char	*str;

	size = 0;
	num = n;
	if (!n)
		return (ft_strdup_new("0"));
	size = calculate_size_hex(num, 0);
	str = malloc(size + 1);
	if (!str)
	{
		check_errors(1, 0);
		return (NULL);
	}
	create_number_hex(str, size, num, hex_a);
	revert_string(str, size);
	*(str + size) = '\0';
	return (str);
}
