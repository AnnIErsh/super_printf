/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:50:47 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 10:54:43 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string on which to iterate.
f: The function to apply to each character.

Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.

*/

#include "libft.h"

static void	apply(char *s, void (*f)(unsigned int, char *), size_t i)
{
	if (*s)
	{
		(*f)(i, s);
		i++;
		s++;
		return (apply(s, f, i));
	}
	return ;
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	if (!s || !f)
		return ;
	apply(s, f, 0);
}
