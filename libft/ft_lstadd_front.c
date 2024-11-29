/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:47:13 by aershova          #+#    #+#             */
/*   Updated: 2023/05/24 12:49:52 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.

Adds the node ’new’ at the beginning of the list.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
int main()
{
	t_list *test;
	t_list *test1;
	char *str = "HELLO";
	char *str2 = "world";
	test = ft_lstnew(str);
	test1 = ft_lstnew(str2);
	ft_lstadd_front(&test, test);
	return (0);	
}
*/
