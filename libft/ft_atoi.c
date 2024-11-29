/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:59:55 by aershova          #+#    #+#             */
/*   Updated: 2023/05/21 11:15:00 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The atoi() function converts the initial portion of
	 the string pointed to by str to int representation
	  The atoi() functions are thread-safe
*/

#include "libft.h"

static void	make_digit(const char *str, size_t i, size_t *res)
{
	if (str + i && (*(str + i) >= '0' && *(str + i) <= '9'))
	{
		*res *= 10;
		*res += *(str + i) - '0';
		i++;
		return (make_digit(str, i, res));
	}
	else
		return ;
}

static int	check_spaces(const char *str)
{
	if (str && (*str == ' ' || *str == '\n'
			|| *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\f'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (check_spaces(str + i))
		i++;
	if (*(str + i) == '+')
		i++;
	else if (*(str + i) == '-')
	{
		sign = -1;
		i++;
	}
	if (!(*(str + i) >= '0' && *(str + i) <= '9'))
		return (0);
	make_digit(str + i, 0, &res);
	return (res * sign);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "-123123";
	char str1[] = "-123123";

	int res = atoi(str);
	int res1 = ft_atoi(str1);
	printf("%d\n", res);
	printf("%d\n", res1);

	return 0;
}
*/
