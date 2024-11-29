/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:45:55 by aershova          #+#    #+#             */
/*   Updated: 2023/05/20 13:11:39 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The calloc() function contiguously allocates enough space for
count objects that are size bytes of memory each and returns
a pointer to the allocated memory. 
The allocated memory is filled with bytes of value zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;

	mem = (void *)malloc(size * count);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size * count);
	return (mem);
}
