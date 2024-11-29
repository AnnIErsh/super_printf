/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:03:51 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 21:16:14 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strlcat() appends string src to the end of dst.
It will append at most dstsize - strlen(dst) - 1 characters.
It will then NUL-terminate, unless dstsize is 0
or the original dst string was longer than dstsize
(in practice this should not happen as it means that either
dstsize is incorrect or that dst is not a proper string).

If the src and dst strings overlap, the behavior is undefined.

return the total length of the string they tried to create.

For strlcat() that means the initial length of
dst plus the length of src.

1. dstsize <= len_d then ====> len_s + dstsize
2. while (dstsize - strlen(dst) - 1) ===> len_d + len_s


*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = 0;
	len_s = 0;
	i = 0;
	while (*(dst + len_d))
		len_d++;
	while (*(src + len_s))
		len_s++;
	if (dstsize <= len_d)
		return (len_s + dstsize);
	while (dst + len_d + i && src + i
		&& *(src + i) && i < (dstsize - len_d - 1))
	{
		*(dst + len_d + i) = *(src + i);
		i++;
	}
	*(dst + len_d + i) = '\0';
	return (len_d + len_s);
}

/*
#include <stdio.h>
#include <string.h>

void test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[100] = "123456789";
    int r;

    r = strlcat(buffer, string, size);
    printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}

void ft_test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[100] = "123456789";
    int r;

    r = ft_strlcat(buffer, string, size);
    printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}

void test1(int size)
{
    char string[] = "12345678"; // 8
    char buffer[20] = "HelloWorld"; // 10
    int r;

    r = strlcat(buffer, string, size);
    printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}

void test2(int size)
{
    char string[] = "12345678"; // 8
    char buffer[20] = "HelloWorld"; // 10
    int r;

    r = ft_strlcat(buffer, string, size);
    printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}

int main()
{
    test(19);
	ft_test(19);
    test(10);
	ft_test(10);
    test(1);
	ft_test(1);
    test(0);
	ft_test(0);

	test1(16);
	test2(16);

	test1(10);
	test2(10);
	
    return(0);
}
*/