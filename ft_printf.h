/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:34:09 by annaershova       #+#    #+#             */
/*   Updated: 2023/06/25 19:46:35 by annaershova      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		flag_zero;
	int		flag_minus;
	int		flag_space;
	int		flag_hash;
	int		flag_plus;
	int		flag_dot;
	int		width[2];
	int		precision[2];
	va_list	*data;
}	t_format;

int		ft_printf(const char *format, ...);
void	init_empty_object(t_format *object, va_list *ap);
int		count_result(int count_need);
int		ft_putchar_with_count(char c);
void	ft_putstr_with_count(char const *s);
char	*ft_strchr_with_count(const char *s, int c);
void	check_number_format(int *number, char **p_obj);
void	set_sign(char sign, char **str);
void	print_with_length(size_t len, char c);
void	dealloc_str_and_set_new(char **str, char *new_str);
void	check_number_format(int *number, char **p_obj);
void	parse_width_and_length(t_format *object, char **p_obj);
char	*unsigned_itoa(unsigned int n);
char	*unsigned_hex_itoa(size_t n, char hex_a);
char	set_or_get_hex_case(char c, int get);
void	set_hash_str(char **hash_str, char c);
void	print_percent(int *obj_len, int print_need, t_format *obj);
void	print_char(int *obj_len, int print_need, t_format *obj);
void	print_string(int *obj_len, int print_need, t_format *obj);
void	print_int(int *obj_len, int print_need, t_format *obj);
void	print_unsigned(int *obj_len, int print_need, t_format *obj);
void	print_hex(int *obj_len, int print_need, t_format *obj);
void	print_pointer(int *obj_len, int print_need, t_format *obj);
int		check_errors(int set_error, int end);
char	*ft_strjoin_new(char const *s1, char const *s2);
char	*ft_strdup_new(const char *s1);
char	*ft_itoa_new(int n);
char	*alloc_check(int size, int sign);

#endif
