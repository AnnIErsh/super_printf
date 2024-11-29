/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:45:55 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 16:54:09 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create_number(size_t i, char *str, size_t len, unsigned long n)
{
	unsigned long	res;

	if (i < len && str + i && n)
	{
		res = n % 10;
		n /= 10;
		*(str + i) = res + '0';
		i++;
		create_number(i, str, len, n);
	}
}

static size_t	calculate_size(unsigned long n, size_t i)
{
	if (n)
	{
		n /= 10;
		i++;
		return (calculate_size(n, i));
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

char	*unsigned_itoa(unsigned int n)
{
	size_t	num;
	size_t	size;
	char	*str;

	size = 0;
	num = n;
	if (!n)
		return (ft_strdup_new("0"));
	size = calculate_size(num, 0);
	str = malloc(size + 1);
	if (!str)
	{
		check_errors(1, 0);
		return (NULL);
	}
	create_number(0, str, size, num);
	revert_string(str, size);
	*(str + size) = '\0';
	return (str);
}
