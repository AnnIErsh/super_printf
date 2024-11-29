/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:10:49 by aershova          #+#    #+#             */
/*   Updated: 2023/06/26 17:43:26 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s1: The string to be trimmed.
set: The reference set of characters to trim.

Return value
The trimmed string.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.

*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	len;
	size_t	i;

	if (s1 && *s1 && set && *set && ft_strchr(set, *s1))
	{
		s1++;
		return (ft_strtrim(s1, set));
	}
	len = ft_strlen(s1);
	i = len;
	while (i && s1 + i - 1 && *(s1 + i - 1)
		&& ft_strchr(set, *(s1 + i - 1)))
		i--;
	copy = ft_substr(s1, 0, i);
	return (copy);
}

/*
int main()
{
	char *str = "ddd...gsjdhfgsjdh dddd HEllo ddddd";
	//char *str = "";
	char *str1 = ft_strtrim(str, ".d");
	
	return (0);
}
*/
