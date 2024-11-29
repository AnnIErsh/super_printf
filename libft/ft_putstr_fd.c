/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:31:31 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 19:42:52 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string to output.
fd: The file descriptor on which to write.

Outputs the string ’s’ to the given file
descriptor.

*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s + i && *(s + i))
	{
		ft_putchar_fd(*(s + i), fd);
		i++;
	}
}
