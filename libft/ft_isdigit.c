/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:08:42 by aershova          #+#    #+#             */
/*   Updated: 2023/05/16 10:05:12 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The isdigit() function tests for a decimal digit character.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
