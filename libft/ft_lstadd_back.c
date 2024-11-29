/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:43:37 by aershova          #+#    #+#             */
/*   Updated: 2023/05/24 16:34:31 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.

Adds the node ’new’ at the end of the list.

*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
			return ;
		}
		*lst = new;
	}
}

/*
#include "stdio.h"
int main()
{
	t_list *test1;
	t_list *test2;
	t_list *test3;
	t_list *test4;
	char *str1 = "3HELLO";
	char *str2 = "2world";
	char *str3 = "1!!!!!!!";
	char *str4 = "add back str";
	test1 = ft_lstnew(str1);
	test2 = ft_lstnew(str2);
	test3 = ft_lstnew(str3);
	test4 = ft_lstnew(str4);
	ft_lstadd_front(&test1, test2);
	ft_lstadd_front(&test1, test3);
	int size = ft_lstsize(test1);
	printf("%d\n", size);

	t_list *last;
	last = ft_lstlast(test1);
	printf("last node before: %s\n", (char *)last->content);
	ft_lstadd_back(&test1, test4);
	last = ft_lstlast(test4);
	printf("last node after: %s\n", (char *)last->content);
	return (0);
}
*/