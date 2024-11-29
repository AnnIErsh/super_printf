/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:58:43 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:21:10 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strnstr() function locates the first occurrence of the
null-terminated string needle in the string haystack,
where not more than len characters are searched. 
Characters that appear after a `\0' character are not searched.  Since the
strnstr() function is a FreeBSD specific API,
it should only be used when portability is not a concern.

RETURN VALUES
     If needle is an empty string, haystack is returned;
	 if needle occurs nowhere in haystack, NULL is returned;
	 otherwise a pointer to the first character
	 of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*(needle))
		return ((char *)haystack);
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (haystack + i + j && *(haystack + i + j)
			&& needle + j && *(needle + j) && i + j < len)
		{
			if (*(haystack + i + j) == *(needle + j))
				j++;
			else
				break ;
		}
		if (needle + j && !*(needle + j))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "AjkdhfkjshdfHelloklsajalksd";
	char substr[] = "Hello";
	char str1[] = "AjkdhfkjshdfHelloklsajalksd";
	char substr1[] = "Hello";

	char *res = ft_strnstr(str, substr, 20);
	char *res1 = strnstr(str1, substr1, 20);
	printf("%s\n", res);
	printf("%s\n", res1);

	printf("%s\n", ft_strnstr("aaxx", "xx", 4));
	printf("%s\n", strnstr("aaxx", "xx", 4));

	return 0;
}
*/
