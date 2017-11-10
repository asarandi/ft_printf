/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:37:11 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/08 21:18:25 by asarandi         ###   ########.fr       */
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

# define FLAG_HASHTAG	1
# define FLAG_ZERO		2
# define FLAG_MINUS		4
# define FLAG_SPACE		8
# define FLAG_PLUS		16

typedef	struct	s_placeholder
{
	int				flags;
	int				have_flags;
	int				width;
	int				have_width;
	int				precision;
	int				have_precision;
	int				length;
	int				have_length;
	char			type;
	int				have_type;
	uintmax_t		n;
	char			sign;
	int				invalid;
	char			*location;
	unsigned char	*output;
	int				char_count;
}	t_placeholder;

char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);
void		parse_placeholder(char **fmt, va_list *ap, t_placeholder *placeholder);
int			init_placeholder(t_placeholder *placeholder);
int			wchar_to_utf8(unsigned int wchar, unsigned char *output);
char		*ft_strtoupper(char *s);
void		string_prefix(t_placeholder *ph, char *prefix);
void		string_suffix(t_placeholder *ph, char *suffix);
int			is_numeric(char type);
int			get_default_length(char type);
int			is_signed(char type);
int			is_decimal(char type);
int			get_base(char type);
void		trim_bits(t_placeholder *placeholder);
void		check_negative(t_placeholder *placeholder);
void		make_numeric_output(t_placeholder *placeholder);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memalloc(size_t size);
void		get_placeholder_flags(char **fmt, t_placeholder *placeholder);
void		get_placeholder_width(char **fmt, va_list *ap, t_placeholder *ph);
void		get_placeholder_precision(char **fmt, va_list *ap, t_placeholder *ph);
void		get_placeholder_length(char **fmt, t_placeholder *placeholder);
int			ft_printf(const char *restrict format, ...);

#endif
