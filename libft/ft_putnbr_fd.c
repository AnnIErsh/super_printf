/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:51:13 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 20:52:52 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
n: The integer to output.
fd: The file descriptor on which to write.

Outputs the integer ’n’ to the given file
descriptor.

*/

#include "libft.h"

static void	print_number(unsigned long num, int fd)
{
	if (num >= 10)
		print_number(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long	num;
	int				sign;

	sign = 0;
	if (n < 0)
	{
		num = (long)n * (-1);
		sign = 1;
	}
	else
		num = (unsigned long)n;
	if (sign)
		ft_putchar_fd('-', fd);
	print_number(num, fd);
}

/*
int main()
{
	ft_putnbr_fd(-2147483647, 0);
	return (0);
}
*/