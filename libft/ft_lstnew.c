/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:32:46 by aershova          #+#    #+#             */
/*   Updated: 2023/05/24 09:11:24 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
content: The content to create the node with.
return value: The new node

Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.

*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_obj;

	new_obj = (t_list *)malloc(sizeof(t_list));
	if (new_obj)
	{
		new_obj->content = content;
		new_obj->next = NULL;
	}
	return (new_obj);
}

/*
#include <stdio.h>

int main ()
{
	t_list *test;
	char *str = "HELLO";

	test = ft_lstnew(str);
	printf("%s\n", test->content);
	return (0);
}
*/