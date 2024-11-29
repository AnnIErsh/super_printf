/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:46:16 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 19:18:09 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_result(int count_need)
{
	static int	i;
	int			result;

	if (count_need == -1)
		i = -1;
	else if (count_need == 1 && i >= 0)
		i++;
	else
	{
		result = i;
		i = 0;
		return (result);
	}
	return (i);
}

int	ft_putchar_with_count(char c)
{
	if (write(1, &c, 1) > 0)
		return (count_result(1));
	return (count_result(-1));
}

void	ft_putstr_with_count(char const *s)
{
	if (!s)
		return ;
	if (*s)
	{
		if (ft_putchar_with_count(*s) < 0)
			return ;
		s++;
		ft_putstr_with_count(s);
	}
}

char	*ft_strchr_with_count(const char *s, int c)
{
	size_t	i;
	int		error;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		error = ft_putchar_with_count(*(s + i));
		if (error < 0)
			return (NULL);
		i++;
	}
	if (!(char)c)
		return ((char *)s + i);
	return (NULL);
}

void	check_number_format(int *number, char **p_obj)
{
	char	*itoa;

	if (!number[0] && number[1])
	{
		itoa = ft_itoa_new(number[1]);
		if (!itoa)
			return ;
		*p_obj += ft_strlen(itoa);
		free(itoa);
	}
}
