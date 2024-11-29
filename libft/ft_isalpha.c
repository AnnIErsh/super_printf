/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:34:02 by aershova          #+#    #+#             */
/*   Updated: 2023/05/19 11:52:27 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The isalpha() function tests for any character
for which isupper(3) or islower(3) is true.
The value of the argument must be representable as an unsigned
char or the value of EOF.
In the ASCII character set, this includes the following characters
(preceded by their numeric values, in octal)
RETURN VALUES
The isalpha() function returns zero if the character
tests false and returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
