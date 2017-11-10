# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 09:00:12 by asarandi          #+#    #+#              #
#    Updated: 2017/11/09 16:20:16 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -g -Wall -Werror -Wextra -I. -c
FILES	= ft_printf.c \
		  libft_functions.c \
		  helper_functions.c \
		  helper_functions_2.c \
		  parse_placeholder.c \
		  wchar_to_utf8.c \
		  print_number.c
OBJ		= $(FILES:%.c=%.o)
SONAME	= libftprintf.so
INC		= libftprintf.h \
		  ft_binary_byte.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

norm:
	norminette $(FILES) $(INC)

debug:
	gcc -g -c -fPIC $(FILES)
	gcc -g -shared -fPIC $(OBJ) -o $(SONAME)

test: re
	rm -rf $(OBJ)
	rm -f test1
	gcc -g test2.c -L. -lftprintf -o test1

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(SONAME)

junk: fclean
	rm -rf .*.swp
	rm -rf *.dSYM
	rm -rf a.out

re: fclean all
