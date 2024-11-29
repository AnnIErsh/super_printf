/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:18:25 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:28:07 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The memcpy() function copies n bytes from memory area src
to memory area dst.  If dst and src overlap, behavior is undefined.
Applications in which dst and src might overlap should use memmove(3) instead.

RETURN VALUES
     The memcpy() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp_d;
	unsigned const char	*tmp_s;
	size_t				i;

	tmp_d = dst;
	tmp_s = src;
	i = 0;
	while (i < n && (tmp_d + i != tmp_s + i))
	{
		*(tmp_d + i) = *(tmp_s + i);
		i++;
	}
	return (dst);
}

/*
#include <string.h>
int main()
{
	char str[] = "Hello wwwww";
	char copy[] = "copy";
	char str1[] = "Hello wwwww";
	char copy1[] = "copy";
	
	printf("test: %s\n", ft_memcpy(str, copy, 3));
	printf("test: %s\n", memcpy(str1, copy1, 3));
}
*/