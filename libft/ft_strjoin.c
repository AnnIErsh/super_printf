/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:58 by aershova          #+#    #+#             */
/*   Updated: 2023/06/25 19:15:26 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
s1: The prefix string.
s2: The suffix string.


Return value
The new string.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.

strlcpy(str, s1, len_s1 + 1) ->> because of the dstsize - 1 in strlcpy

*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		*(str + i++) = *s1++;
	while (s2 && *s2)
		*(str + i++) = *s2++;
	*(str + i) = '\0';
	return (str);
}

/*
int main()
{
	char *str1 = "Hello ";
	char *str2 = "World ;)";
	char *str3 = ft_strjoin(str1, str2);
	
	return (0);
}
*/
