# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 09:00:12 by asarandi          #+#    #+#              #
#    Updated: 2017/11/03 02:00:17 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra
FILES	= ft_printf.c \
		  libft_functions.c \
		  parse_placeholder.c \
		  print_number.c
OBJ		= $(FILES:.c=.o)
SONAME	= libftprintf.so
INC		= libftprintf.h \
		  ft_binary_byte.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ):
	gcc $(CFLAGS) $(FILES)

norm:
	norminette $(FILES) $(INC)

debug:
	gcc -g -c -fPIC $(FILES)
	gcc -g -shared -fPIC $(OBJ) -o $(SONAME)

test:
	rm -f test1
	gcc -g test1.c $(FILES) -o test1

clean:
	rm -f $(OBJ)

fclean:
	clean
	rm -f $(NAME) $(SONAME)

re:
	fclean all
