/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:21:16 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 19:28:36 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
c: The character to output.
fd: The file descriptor on which to write.

Outputs the character ’c’ to the given file
descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
