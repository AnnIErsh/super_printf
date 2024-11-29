/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:16:19 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:16:33 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The strchr() function locates the first occurrence of
c (converted to a char) in the string pointed to by s.
The terminating null character is considered to be part of the string;
therefore if c is `\0', the functions locate the termi-
nating `\0'.

RETURN VALUES
     The functions strchr()
	 return a pointer to the
	 located character, or NULL if the character does not appear in the string.

*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (!(char)c)
		return ((char *)s + i);
	return (NULL);
}

/*
#include <string.h>
int main()
{
	char *str = "teste";
	char *str1 = "teste";
	
	printf("%s\n", ft_strchr(str, 'e'));
	printf("%s\n", strchr(str1, 'e'));
	
}
*/
