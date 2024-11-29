/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:49:57 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 11:00:28 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string on which to iterate.
f: The function to apply to each character.

The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails

Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.

*/

#include "libft.h"

static char	*apply(char *s, char (*f)(unsigned int, char), int i, char *str)
{
	if (*s)
	{
		*str = (*f)(i, *s);
		str++;
		s++;
		i++;
		return (apply(s, f, i, str));
	}
	*str = '\0';
	return (str - i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;

	if (!s || !f)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	str = apply((char *)s, f, 0, str);
	return (str);
}
