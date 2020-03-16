# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 09:00:12 by asarandi          #+#    #+#              #
#    Updated: 2018/01/31 04:15:54 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS += -Wall -Werror -Wextra
SRC += \
    add_precision.c \
    add_width.c \
    colors.c \
    float_cosmetics.c \
    format_csws.c \
    format_ioux.c \
    ft_printf.c \
    get_char.c \
    get_double.c \
    get_specs.c \
    init_lib.c \
    is_format.c \
    iso8601.c \
    libft_functions.c \
    non_numeric.c \
    print_number.c \
    string_op.c \
    wchar_to_utf8.c

OBJ = $(SRC:%.c=%.o)
get_double.o: CFLAGS += -Wno-div-by-zero

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
