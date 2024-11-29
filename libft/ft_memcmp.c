/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:46:14 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:17:35 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memcmp() function compares byte string s1 against byte string s2.
	 Both strings are assumed to be n bytes long.

RETURN VALUES
     The memcmp() function returns zero if the two strings are identical,
	 otherwise returns the difference between the first two differing bytes
	 (treated as unsigned char values,
	 so that `\200' is greater than `\0', for example).  Zero-length
     strings are always identical. 
	 This behavior is not required by C and portable code
	 should only depend on the sign of the returned value.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(tmp1 + i) == *(tmp2 + i))
			i++;
		else
			return (*(tmp1 + i) - *(tmp2 + i));
	}
	return (0);
}
