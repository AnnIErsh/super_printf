/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:40:24 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/26 17:34:20 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*[flags][width][.precision][length]specifier*/

/*
flag ' ' and '0' results in undefined behavior	with 'c' conversion specifier 
flag '0' results in undefined behavior with 's' conversion specifier
--timeout <number of seconds> -- 4 sec bonus
*/

#include "ft_printf.h"

static void	print_obj(t_format *obj, void (*print)(int *, int, t_format *obj))
{
	int		obj_len;
	int		print_len;

	obj_len = 0;
	print_len = 0;
	if (obj->flag_minus)
	{
		print(&obj_len, 1, obj);
		if (obj_len < obj->width[1])
			print_len = obj->width[1] - obj_len;
		print_with_length(print_len, ' ');
	}
	else
	{
		print(&obj_len, 0, obj);
		if (obj_len < obj->width[1])
			print_len = obj->width[1] - obj_len;
		if (obj->flag_zero)
			print_with_length(print_len, '0');
		else
			print_with_length(print_len, ' ');
		print(&obj_len, 1, obj);
	}
}

static void	get_object_type(char c, t_format *object)
{
	if (c == '%')
		print_obj(object, print_percent);
	else if (c == 'c')
		print_obj(object, print_char);
	else if (c == 's')
		print_obj(object, print_string);
	else if (c == 'd' || c == 'i')
		print_obj(object, print_int);
	else if (c == 'u')
		print_obj(object, print_unsigned);
	else if (c == 'x' || c == 'X')
	{
		set_or_get_hex_case(c, 0);
		print_obj(object, print_hex);
	}
	else
		if (c == 'p')
			print_obj(object, print_pointer);
	else
		return ;
}

static void	print_arg_ptr(t_format *object, char **p_obj, const char **format)
{
	(*p_obj)++;
	parse_width_and_length(object, p_obj);
	get_object_type(**p_obj, object);
	*format = ++(*p_obj);
}

static int	find_count_errors(int *count)
{
	int	n;

	n = count_result(0);
	if (n < 0 || check_errors(0, 1))
		return (1);
	*count += n;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	object;
	char		*p_obj;
	int			count;

	if (!format || !*format)
		return (0);
	count = 0;
	va_start(ap, format);
	while (format && *format)
	{
		init_empty_object(&object, &ap);
		p_obj = ft_strchr_with_count(format, '%');
		if (find_count_errors(&count))
			return (-1);
		if (p_obj)
			print_arg_ptr(&object, &p_obj, &format);
		else
			break ;
		if (find_count_errors(&count))
			return (-1);
	}
	va_end(ap);
	return (count);
}
/*
#include <limits.h>
#include <stdio.h>
int main()
{
	int count1 = ft_printf("% 0-11%%c%c%c", 'a', 'b', 'c');
	printf("|%d\n", count1);
	int count2 = printf("% 0-11%%c%c%c", 'a', 'b', 'c');
	printf("|%d\n", count2);
	int count3 = ft_printf(" %c %c %c", '2', 0, '1');
	printf("|%d\n", count3);
	int count4 = printf(" %c %c %c", '2', 0, '1');
	printf("|%d\n", count4);
	int count5 = ft_printf("%*s", -40, "testing testing");
	printf("|%d\n", count5);
	int count6 = printf("%*s", -40, "testing testing");
	printf("|%d\n", count6);
	int count7 = ft_printf("%.0s", "hello");
	printf("|%d\n", count7);
	int count8 = printf("%.0s", "hello");
	printf("|%d\n", count8);
	int count9 = ft_printf("%20.*d", -3, 1);
	printf("|%d\n", count9);
	int count10 = printf("%20.*d", -3, 1);
	printf("|%d\n", count10);
	char *str = "asd";
	int count11 = ft_printf("%-20p", str);
	ft_printf("|%d\n", count11);
	int count12 = printf("%-20p", str);
	printf("|%d\n", count12);
	int count13 = ft_printf("%d", 0);
	printf("|%d\n", count13);
	int count14 = ft_printf("%d", 0);
	printf("|%d\n", count14);
	return (0);
}
*/
