/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:21:01 by aershova          #+#    #+#             */
/*   Updated: 2023/05/19 11:57:10 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The isascii() function tests for an ASCII character, 
 which is any character between 0 and octal 0177 inclusive.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
