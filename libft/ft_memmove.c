/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:40:58 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:34:10 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The memmove() function copies len bytes from string src to string dst. 
The two strings may overlap; the copy is
always done in a non-destructive manner.

RETURN VALUES
    The memmove() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (i)
		{
			i--;
			*((char *)dst + i) = *((const char *)src + i);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((char *)dst + i) = *((const char *)src + i);
			i++;
		}
	}
	return (dst);
}
