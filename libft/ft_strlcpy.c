/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:51:16 by aershova          #+#    #+#             */
/*   Updated: 2023/06/23 22:44:56 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The strlcpy() and strlcat() functions copy and concatenate strings
with the same input parameters and output result as snprintf(3).
They are designed to be safer, more consistent, and less error prone replace-
ments for the easily misused functions strncpy(3) and strncat(3).

strlcpy() and strlcat() take the full size of the destination
buffer and guarantee NUL-termination if there is room.
Note that room for the NUL should be included in dstsize.

strlcpy() copies up to dstsize - 1 characters from
the string src to dst, NUL-terminating the result if dstsize is not 0.

If the src and dst strings overlap, the behavior is undefined.
Besides quibbles over the return type (size_t versus int) and signal
handler safety (snprintf(3) is not entirely safe on some systems),
the following two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

Like snprintf(3), the strlcpy() and strlcat() functions return the total length
of the string they tried to create.  For strlcpy() that means the length of src.
For strlcat() that means the initial length of dst plus the length of src.
If the return value is >= dstsize, the output string has been truncated.
It is the caller's responsibility to handle this.

return the total length of the string they tried to create.

For strlcpy() that means the length of src

If the src and dst strings overlap, the behavior is undefined.

*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = 0;
	while (*(src + len_s))
		len_s++;
	if (!dstsize)
		return (len_s);
	while (i < dstsize - 1
		&& src + i && *(src + i) && dst + i)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (len_s);
}

/*
#include <stdio.h>
#include <string.h>

void test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[40] = "asdasda";
    int r;

    r = strlcpy(buffer, string, size);
    printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}

void ft_test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[40] = "asdasda";
    int r;

    r = ft_strlcpy(buffer, string, size);
    printf("Kopied '%s' into '%s', length %d\n", string, buffer, r);
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

    return(0);
}
*/