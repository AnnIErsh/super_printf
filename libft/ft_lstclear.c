/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:17:37 by aershova          #+#    #+#             */
/*   Updated: 2023/06/26 17:36:25 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: The address of a pointer to a node.
del: The address of the function used to delete
the content of the node.

Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL.

*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!del || !lst)
		return ;
	if (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
		ft_lstclear(lst, del);
	}
	free(*lst);
}

/*
#include "stdio.h"
void	test_del(void *str)
{
	char *test_str = "test test teeeest";
	printf("\n%s tesl del func\n", test_str);
	str = test_str;
}
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

	ft_lstclear(&test2, test_del);
	printf("content from the last node: %s\n", (char *)last->content);
	return (0);
}
*/
