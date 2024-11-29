/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:25:42 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/23 00:08:52 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_format *object, char **str)
{
	while (*str && (**str == ' ' || **str == '0' || **str == '-'
			|| **str == '#' || **str == '+' || **str == '*'))
	{
		if (**str == ' ')
			object->flag_space = 1;
		if (**str == '0')
			object->flag_zero = 1;
		if (**str == '-')
			object->flag_minus = 1;
		if (**str == '+')
			object->flag_plus = 1;
		if (**str == '#')
			object->flag_hash = 1;
		if (**str == '*')
		{
			if (!object->flag_dot)
				object->width[0] = 1;
			else
				object->precision[0] = 1;
		}
		(*str)++;
	}
}

static void	parse_width(t_format *object, char **str)
{
	long	width;

	width = 0;
	if (ft_isdigit(**str))
		width = ft_atoi(*str);
	else if (object->width[0])
	{
		width = va_arg(*object->data, int);
		if (width < 0)
		{
			width *= -1;
			object->flag_minus = 1;
		}
	}
	if (width > 2147483647)
		width = 0;
	object->width[1] = width;
}

static void	parse_after_dot_flag(t_format *object, char **str)
{
	while (*str && **str == '.')
	{
		object->flag_dot = 1;
		(*str)++;
		if (*str && **str == '*')
		{
			object->precision[0] = 1;
			(*str)++;
			break ;
		}
	}
	while (*str && (**str == ' ' || **str == '0'))
		(*str)++;
}

static void	parse_length(t_format *object, char **str)
{
	long	length;

	length = 0;
	if (ft_isdigit(**str))
		length = ft_atoi(*str);
	else if (object->precision[0])
		length = va_arg(*object->data, int);
	if (length > 2147483647)
		length = 0;
	object->precision[1] = length;
}

void	parse_width_and_length(t_format *object, char **p_obj)
{
	parse_flags(object, p_obj);
	parse_width(object, p_obj);
	check_number_format(object->width, p_obj);
	parse_after_dot_flag(object, p_obj);
	parse_length(object, p_obj);
	check_number_format(object->precision, p_obj);
}
