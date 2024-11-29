/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:40:22 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:14:40 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The bzero() function writes n zeroed bytes to the string s.
If n is zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;

	ch = s;
	while (n)
	{
		*ch++ = '\0';
		n--;
	}
}
