# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 09:00:12 by asarandi          #+#    #+#              #
#    Updated: 2017/10/30 09:18:13 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra
FILES	= $(wildcard *.c)
OBJ		= $(FILES:.c=.o)
SONAME	= libftprintf.so
INC		= libftprintf.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

norm:
	norminette $(FILES) $(INC)

debug:
	gcc -g -c -fPIC $(FILES)
	gcc -g -shared -fPIC $(OBJ) -o $(SONAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(SONAME)

re: 
	fclean all
