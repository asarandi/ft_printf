/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:21:32 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/09 16:22:36 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <locale.h>
#include <wchar.h>

void	get_placeholder_type(char **fmt, t_placeholder *ph)
{
	const char*	valid_types = "dDiuUoOxXpcCsS";
	int	i;

	i = 0;
	(*ph).type = **fmt;
	(*ph).invalid = 1;
	while (valid_types[i])
	{
		if (**fmt == valid_types[i])
		{
			(*ph).invalid = 0;
			break ;
		}
		i++;
	}
	(*fmt)++;
	return ;
}

int	is_deprecated(char type)
{
	if ((type == 'D') || (type == 'O') || (type == 'U'))
		return (1);
	return (0);
}

unsigned char	*get_wchar(va_list *ap, t_placeholder *ph)
{
	unsigned char buffer[5];
	unsigned int wchar;
	unsigned char *result;

	int	i;

	i = 0;
	while (i < 5)
		buffer[i++] = 0;
	wchar = (unsigned int) va_arg(*ap, wchar_t);
	i = wchar_to_utf8(wchar, buffer);
	if ((result = ft_memalloc(8)) == NULL)
		return (NULL);
	i = 0;
	while (i < 5)
	{
		result[i] = buffer[i];
		i++;
	}
	if (result[0] == 0)
		(*ph).char_count = 1;
	return (result);
}

unsigned char *get_char(va_list *ap, t_placeholder *ph)
{
	unsigned char *c;

	if ((*ph).length > 32)
		return (get_wchar(ap, ph));
	if ((c = ft_memalloc(4)) == NULL)
		return (NULL);
	c[0] = (unsigned char) va_arg(*ap, int);
	(*ph).char_count = 1;
	return (c);
}

int	get_wstr_length(wchar_t *wstr)
{
	int				result;
	wchar_t			c;
	unsigned char	buffer[5];

	c = 0;
	result = 0;
	while (wstr[c])
	{
		result += wchar_to_utf8(wstr[c], buffer);
		c++;
	}
	return (result);
}

unsigned char *get_wide_string(va_list *ap, t_placeholder *ph)
{
	wchar_t			*wstr;
	wchar_t			wchar;
	int				length;
	unsigned char	*output;
	int				i;

	wstr = va_arg(*ap, wchar_t *);
	if (wstr == NULL)
	{
		(*ph).char_count = 6;
		return ((unsigned char *)ft_strdup("(null)"));
	}
	length = get_wstr_length(wstr);
	if ((output = ft_memalloc(length + 8)) == NULL)
		return (NULL);
	wchar = 0;
	i = 0;
	while (wstr[wchar])
	{
		i += wchar_to_utf8(wstr[wchar], &output[i]);
		wchar++;
	}
	(*ph).char_count = i;
	return (output);
}

unsigned char *get_string(va_list *ap, t_placeholder *ph)
{
	unsigned char *str;
	unsigned char *result;

	if ((*ph).length > 32)
		return (get_wide_string(ap, ph));
	str = va_arg(*ap, unsigned char *);
	if (str == NULL)
		result = (unsigned char *)ft_strdup("(null)");
	else
		result = (unsigned char *)ft_strdup((char *)str);
	(*ph).char_count = ft_strlen((char *)result);
	return (result);
}

void	make_non_numeric(t_placeholder *ph, va_list *ap)
{
	if ((*ph).type == 's')
		(*ph).output = get_string(ap, ph);
	else if ((*ph).type == 'S')
		(*ph).output = get_wide_string(ap, ph);
	else if ((*ph).type == 'C')
		(*ph).output = get_wchar(ap, ph);
	else if ((*ph).type == 'c')
		(*ph).output = get_char(ap, ph);
	else
	{
		(*ph).invalid = 1;
		(*ph).output = ft_memalloc(2);
		(*ph).output[0] = (*ph).type;
		(*ph).char_count = 1;
	}
}


void	add_string_precision(t_placeholder *ph)
{
		int	i;
		if (((*ph).type == 's') && ((*ph).length <= 32))
		{
			i = (*ph).precision;
			if (((*ph).have_precision) && (i >= 0))
			{
				(*ph).output[i] = 0;
				(*ph).char_count = ft_strlen((char *)(*ph).output);
			}
		}
}

void	add_precision(t_placeholder *ph)
{
	if (((*ph).have_precision) && (is_numeric((*ph).type)))
	{
		while ((*ph).precision > (*ph).char_count)
			string_prefix(ph, "0");
		(*ph).flags &= ~(1 << 1); //clear FLAG_ZERO
		if (((*ph).have_precision) && ((*ph).precision == 0) && ((*ph).n == 0))
		{
			(*ph).output[0] = 0;
			(*ph).char_count = 0;
		}
	}
	else
		add_string_precision(ph);
}

void	add_width(t_placeholder *ph)
{
	if ((*ph).have_width)
	{
		if ((*ph).flags & FLAG_MINUS)
		{
			while ((*ph).width > (*ph).char_count)
				string_suffix(ph, " ");
			(*ph).flags &= ~(1 << 1); //clear FLAG_ZERO
		}
		else
		{
			while ((*ph).width > (*ph).char_count)
			{
				if ((*ph).flags & FLAG_ZERO)	
					string_prefix(ph, "0");
				else
					string_prefix(ph, " ");

			}
		}
	}
}

void	flag_space(t_placeholder *ph)
{
	if ((is_signed((*ph).type)) && ((*ph).sign == '+'))
	{
		if ((*ph).output[0] != ' ')
			string_prefix(ph, " ");
	}
}

void	flag_plus(t_placeholder *ph)
{
	(*ph).flags &= ~(1 << 3); //clear FLAG_SPACE
	if ((*ph).sign == '+')
		string_prefix(ph, "+");
	else
		string_prefix(ph, "-");
}

void	format_integer(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	if ((*ph).flags & FLAG_ZERO)
	{
		if (((*ph).flags & FLAG_PLUS) || ((*ph).sign == '-'))
		{
			(*ph).char_count++;
			add_width(ph);
			(*ph).char_count--;
		}
	}
	if (((*ph).flags & FLAG_PLUS) && (is_signed((*ph).type)))
		flag_plus(ph);
	else if ((*ph).sign == '-')
		string_prefix(ph, "-");
	add_width(ph);
	if ((*ph).flags & FLAG_SPACE)
		flag_space(ph);
}

void	format_octal(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	if ((*ph).flags & FLAG_HASHTAG)
	{
		if ((*ph).output[0] != '0')
			string_prefix(ph, "0");
	}
	add_width(ph);
}

void	format_hex(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	if (((*ph).flags & FLAG_HASHTAG) && ((*ph).n != 0))
	{
	   	if ((*ph).flags & FLAG_ZERO)
		{
			(*ph).char_count += 2;
			add_width(ph);
			string_prefix(ph, "0x");
			(*ph).char_count -= 2;
		}
		else
			string_prefix(ph, "0x");
	}
	add_width(ph);
	if ((*ph).type == 'X')
		ft_strtoupper((char *)(*ph).output);
}

void	format_string(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
}

void	format_wide_string(t_placeholder *ph)
{

	add_precision(ph);
	add_width(ph);
}

void	format_unsigned_int(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	add_width(ph);
}

void	format_char(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
}

void	format_wide_char(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
}

void	format_pointer(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	(*ph).char_count = ft_strlen((char *)(*ph).output) + 2;
	if ((*ph).flags & FLAG_ZERO)
		add_width(ph);
	string_prefix(ph, "0x");
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_width(ph);
}

void	format_invalid(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
	(*ph).char_count = ft_strlen((char *)(*ph).output);
}

void	format_output(char type, t_placeholder *ph)
{
	if ((type == 'd') || (type == 'i') || (type == 'D'))
		format_integer(ph);
	else if ((type == 'o') || (type == 'O'))
		format_octal(ph);
	else if ((type == 'x') || (type == 'X'))
		format_hex(ph);
	else if (type == 's')
		format_string(ph);
	else if (type == 'S')
		format_wide_string(ph);
	else if ((type == 'u') || (type == 'U'))
		format_unsigned_int(ph);
	else if (type == 'c')
		format_char(ph);
	else if (type == 'C')
		format_wide_char(ph);
	else if (type == 'p')
		format_pointer(ph);
	else
		format_invalid(ph);
}

void	parse_placeholder(char **fmt, va_list *ap, t_placeholder *ph)
{
	(*ph).location = *fmt;
	get_placeholder_flags(fmt, ph);
	get_placeholder_width(fmt, ap, ph);
	get_placeholder_precision(fmt, ap, ph);
	get_placeholder_length(fmt, ph);
	get_placeholder_type(fmt, ph);
	if (is_numeric((*ph).type))
	{
		(*ph).n = (uintmax_t)va_arg(*ap, uintmax_t);
		if ((is_deprecated((*ph).type)) || ((*ph).length == 0))
			(*ph).length = get_default_length((*ph).type);
		if ((*ph).length < get_default_length((*ph).type))
			trim_bits(ph);
		make_numeric_output(ph);
	}
	else
		make_non_numeric(ph, ap);
	format_output((*ph).type, ph);
}

int	init_placeholder(t_placeholder *ph)
{
	(*ph).flags = 0;
	(*ph).have_flags = 0;
	(*ph).width = 0;
	(*ph).have_width = 0;
	(*ph).precision = 0;
	(*ph).have_precision = 0;
	(*ph).length = 0;
	(*ph).have_length = 0;
	(*ph).type = 0;
	(*ph).have_type = 0;
	(*ph).n = 0;
	(*ph).sign = 0;
	(*ph).invalid = 0;
	(*ph).location = 0;
	(*ph).output = 0;
	(*ph).char_count = 0;
	return (0);
}

int	main_routine(const char *restrict *format, va_list *ap)
{
	char	*fmt;
	t_placeholder	placeholder;

	fmt = (char *)*(format);
	init_placeholder(&placeholder);
	parse_placeholder(&fmt, ap, &placeholder);
	if (placeholder.char_count == 0)
		placeholder.char_count = ft_strlen((char *)placeholder.output);
	write(1, placeholder.output, placeholder.char_count);
	free(placeholder.output);
	*(format) = (char *)fmt;
	return (placeholder.char_count);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	int				count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{ 
			while ((*format) && (*format != '%'))
			{
				write(1, format++, 1);
				count++;
			}
			if ((*format == '%') && (*(format + 1) == '%'))
			{
				write(1, format++, 1);
				format++;
				count++;
			}
			else if (*format)
					count += main_routine(&format, &ap);
	}
	va_end(ap);
	return (count);
}
