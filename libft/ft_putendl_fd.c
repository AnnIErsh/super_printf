/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:45:51 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 19:49:23 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string to output.
fd: The file descriptor on which to write.

Outputs the string ’s’ to the given file descriptor
followed by a newline.

*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
