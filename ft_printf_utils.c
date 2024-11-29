/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:06:19 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 19:14:10 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_faster(char **str, char const *s, size_t *i)
{
	if (s && *s)
	{
		*(*str + (*i)++) = *s++;
		make_faster(str, s, i);
	}
	else
		return ;
}

char	*ft_strjoin_new(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
	{
		check_errors(1, 0);
		return (NULL);
	}
	i = 0;
	make_faster(&str, s1, &i);
	make_faster(&str, s2, &i);
	*(str + i) = '\0';
	return (str);
}

char	*ft_strdup_new(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = ft_strlen(s1);
	i = 0;
	copy = (char *)malloc(len + 1);
	if (copy)
	{
		while (i < len && s1 + i)
		{
			*(copy + i) = *(s1 + i);
			i++;
		}
		*(copy + i) = '\0';
	}
	else
	{
		check_errors(1, 0);
		return (NULL);
	}
	return (copy);
}

int	check_errors(int set_error, int end)
{
	static int	error_i;
	int			result;

	if (set_error)
		error_i = 1;
	if (end)
	{
		result = error_i;
		error_i = 0;
		return (result);
	}
	return (error_i);
}

void	init_empty_object(t_format *object, va_list *ap)
{
	object->flag_hash = 0;
	object->flag_minus = 0;
	object->flag_space = 0;
	object->flag_zero = 0;
	object->flag_plus = 0;
	object->flag_dot = 0;
	object->precision[0] = 0;
	object->precision[1] = 0;
	object->width[0] = 0;
	object->width[1] = 0;
	object->data = ap;
}
