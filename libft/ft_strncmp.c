/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:30:11 by aershova          #+#    #+#             */
/*   Updated: 2023/05/20 10:46:42 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strcmp() and strncmp() functions
	 lexicographically compare the null-terminated strings s1 and s2.

     The strncmp() function compares not more than n characters. 
	 Because strncmp() is designed for comparing strings rather
	 than binary data, characters that appear
	 after a `\0' character are not compared.

RETURN VALUES
     The strcmp() and strncmp() functions return an integer
	 greater than, equal to, or less than 0, according as the string s1 is
	 greater than, equal to, or less than the string s2. 
	 The comparison is done using unsigned characters, so that
     `\200' is greater than `\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_1;
	unsigned char	*tmp_2;

	i = 0;
	tmp_1 = (unsigned char *)s1;
	tmp_2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (tmp_1 + i && *(tmp_1 + i)
		&& tmp_2 + i && *(tmp_2 + i) && i < n)
	{
		if (*(tmp_1 + i) == *(tmp_2 + i))
			i++;
		else
			break ;
	}
	if (i == n)
		return (0);
	return (*(tmp_1 + i) - *(tmp_2 + i));
}
