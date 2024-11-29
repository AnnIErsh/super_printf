/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:57:22 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:44:42 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters
s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring.

Return value 
The substring.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size - start < len)
		len = size - start;
	if (start < size)
		s += start;
	else
		return (ft_strdup(""));
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(substr + i) = *(s + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}

/*
#include <string.h>
int main()
{
	char *str = "4545";
	char *newstr = ft_substr(str, 1, 30);

	//ft_substr("hola", 4294967295, 18446744073709551615)
	ft_substr("hola", 4294967295, 0);
	printf("%s\n", newstr);
	return (0);
}
*/