/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:38:41 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:16:48 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memchr() function locates the first
	 occurrence of c (converted to an unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located,
	 or NULL if no such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (*(tmp + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
