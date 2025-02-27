/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:33:29 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 19:29:04 by annaershova      ###   ########.fr       */
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

static void	revert_string(char *str, size_t size, size_t sign)
{
	size_t	i;
	size_t	j;

	if (sign)
		*(str + size) = '-';
	size += sign;
	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		swap(str + i, str + j);
		i++;
		j--;
	}
}

char	*ft_itoa_new(int n)
{
	unsigned long	num;
	size_t			size;
	int				sign;
	char			*str;

	sign = 0;
	size = 0;
	if (!n)
		return (ft_strdup_new("0"));
	if (n < 0)
	{
		num = (long)n * (-1);
		sign = 1;
	}
	else
		num = (unsigned long)n;
	size = calculate_size(num, 0);
	str = alloc_check(size, sign);
	if (!str)
		return (NULL);
	create_number(0, str, size, num);
	revert_string(str, size, sign);
	*(str + size + sign) = '\0';
	return (str);
}
