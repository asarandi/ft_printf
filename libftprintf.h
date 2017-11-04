/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:37:11 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/03 18:12:56 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include "ft_binary_byte.h"

int			get_placeholder_length(char **fmt);
int			printf_is_numeric(char *fmt);
int			printf_get_default_length(char *fmt);
int			printf_is_signed(char *fmt);
int			printf_is_decimal(char *fmt);
int			printf_get_base(char *fmt);
uintmax_t	trim_bits(uintmax_t n, int number_of_bits);
int			check_negative(uintmax_t *n, int number_of_bits, int signedness);
char		*print_decimal(uintmax_t n, int number_of_bits, int signedness);
char		*print_octohex(uintmax_t n, int number_of_bits, int base);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memalloc(size_t size);
int			get_placeholder_flags(char **fmt);
int			get_placeholder_width(char **fmt, va_list *ap);
int			get_placeholder_precision(char **fmt, va_list *ap);
int			ft_printf(const char *restrict format, ...);

#endif
