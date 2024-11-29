/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:24:32 by aershova          #+#    #+#             */
/*   Updated: 2023/05/23 09:37:02 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string to be split.
c: The delimiter character.

Return value
The array of new strings resulting from the split.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.

*/

#include "libft.h"

static int	calculate_column(char *s, char c, size_t i, size_t n_column)
{
	if (!s)
		return (0);
	while (*(s + i) && *(s + i) == c)
		i++;
	while (*(s + i))
	{
		while (*(s + i) && *(s + i) != c)
			i++;
		n_column++;
		return (calculate_column(s, c, i, n_column));
	}
	return (n_column);
}

static size_t	count_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	dealloc_row(char **buff, size_t count)
{
	if (count)
	{
		count--;
		dealloc_row(buff, count);
		free(*(buff + count));
		*buff = NULL;
	}
	free(buff);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;
	size_t	n_column;
	size_t	i;

	n_column = calculate_column((char *)s, c, 0, 0);
	buff = (char **)ft_calloc((n_column + 1), sizeof(char *));
	if (!buff)
		return (NULL);
	i = 0;
	while (i < n_column)
	{
		while (*s && *s == c)
			s++;
		*(buff + i) = ft_substr(s, 0, count_len((char *)s, c));
		if (!*(buff + i))
		{
			dealloc_row(buff, i);
			return (NULL);
		}
		i++;
		s += count_len(s, c);
	}
	*(buff + n_column) = NULL;
	return (buff);
}

/*
int main()
{
	char *str = "....zwerw...Hello....ggg..sdfsdf sss ddd...";
	char **res = ft_split(str, '.');
	for (int i = 0; i < 5; i++)
	{
		char *s = *(res + i);
		printf("%s\n", *(res + i));
	}
	return (0);
}
*/
