/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:28 by aershova          #+#    #+#             */
/*   Updated: 2023/05/20 12:44:37 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strrchr() function is identical to strchr(),
except it locates the last occurrence of c.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len + 1)
	{
		if (*(s + len) == (char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
