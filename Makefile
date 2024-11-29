# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annaershova <annaershova@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 18:39:42 by annaershova       #+#    #+#              #
#    Updated: 2023/06/26 17:50:31 by annaershova      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c \
		parse_format.c \
		count_result.c \
		unsigned_itoa.c \
		hex_itoa.c \
		ft_printf_utils.c \
		ft_printf_utils1.c \
		ft_printf_utils2.c  \
		ft_printf_utils3.c \
		integers_print.c \
		string_print.c \
		char_print.c \
		percent_print.c \
		unsigned_print.c \
		hex_print.c \
		pointer_print.c
		
OBJ_FORLDER = objs
OBJ = $(SRC:%.c=$(OBJ_FORLDER)/%.o)

LIBFT = ./libft/libft.a

all: $(NAME)

$(OBJ_FORLDER)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "compiling....."

$(NAME): $(LIBFT) $(OBJ_FORLDER) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@echo "libftprintf created"

$(LIBFT):
	@make --directory ./libft all
	
$(OBJ_FORLDER):
	@mkdir -p $(OBJ_FORLDER)

bonus: all
		
clean:
	@make --directory ./libft clean
	@rm -rf $(OBJ_FORLDER)
	@echo "clean obj printflib"

fclean: clean
	@make --directory ./libft fclean
	@rm -rf $(NAME)
	@echo "clean printflib"
	
re: fclean all
	@echo "recompile library printflib"

.PHONY: re fclean clean all bonus libft