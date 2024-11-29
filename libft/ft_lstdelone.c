/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:36:47 by aershova          #+#    #+#             */
/*   Updated: 2023/05/25 10:45:41 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: The node to free.
del: The address of the function used to delete
the content.

Return value
Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
	}
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

	ft_lstdelone(test4, test_del);
	printf("delete content: %s\n", (char *)test1->content);
	return (0);
}
*/