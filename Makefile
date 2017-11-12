# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 09:00:12 by asarandi          #+#    #+#              #
#    Updated: 2017/11/11 22:31:08 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -g -Wall -Werror -Wextra -I. -c
FILES	=	add_precision.c \
			add_width.c \
			format_ioxf.c \
			format_suc.c \
			ft_printf.c \
			get_char.c \
			get_double_misc.c \
			get_specs.c \
			init_lib.c \
			is_format.c \
			libft_functions.c \
			print_number.c \
			string_op.c \
			wchar_to_utf8.c \
			iso8601.c \
			colors.c 
OBJ		= $(FILES:%.c=%.o)
INC		= libftprintf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(SONAME)

re: fclean all
