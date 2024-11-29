/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:55:58 by aershova          #+#    #+#             */
/*   Updated: 2023/06/25 00:10:03 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The strdup() function allocates sufficient memory for a copy
 of the string s1, does the copy, and returns a pointer to it.
 The pointer may subsequently be used as an argument to the function free(3).
 If insufficient memory is available,
 NULL is returned and errno is set to ENOMEM.

 If insufficient memory is available, NULL is returned 
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
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
		return (NULL);
	return (copy);
}

/*
#include <string.h>
int main()
{
	char str[] = "Hello wwwww";
	char *copy = strdup(str);

	char str1[] = "Hello wwwww";
	char *copy1 = strdup(str1);
	
	
	printf("test: %s len: %lu\n", copy, ft_strlen(copy));
	printf("test: %s len: %lu\n", copy1, ft_strlen(copy1));
}
*/
