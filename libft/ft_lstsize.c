/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:23:08 by aershova          #+#    #+#             */
/*   Updated: 2023/05/24 12:50:05 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: The beginning of the list.

return value
The length of the list

Counts the number of nodes in a list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
#include "stdio.h"

int main()
{
	t_list *test1;
	t_list *test2;
	t_list *test3;
	char *str1 = "HELLO";
	char *str2 = "world";
	char *str3 = "!!!!!!!";
	test1 = ft_lstnew(str1);
	test2 = ft_lstnew(str2);
	test3 = ft_lstnew(str3);
	ft_lstadd_front(&test1, test2);
	ft_lstadd_front(&test1, test3);
	int size = ft_lstsize(test1);
	printf("%d\n", size);
	return (0);
}
*/