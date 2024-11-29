/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:26:36 by aershova          #+#    #+#             */
/*   Updated: 2023/05/16 12:54:51 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The isprint() function tests for any printing character, including space (` ').
The value of the argument must be representable as
an unsigned char or the value of EOF.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
