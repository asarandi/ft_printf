/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_placeholder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:55:33 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/05 01:52:11 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_placeholder_flags(char **fmt)
{
	int	flags;

	flags = 0;
	if (**fmt == '%')
		(*fmt)++;
	while (**fmt)
	{
		if (**fmt == '#')
			flags |= FLAG_HASHTAG;
		else if (**fmt == '0')
			flags |= FLAG_ZERO;
		else if (**fmt == '-')
			flags |= FLAG_MINUS;
		else if (**fmt == ' ')
			flags |= FLAG_SPACE;
		else if (**fmt == '+')
			flags |= FLAG_PLUS;
		else
			return (flags);
		(*fmt)++;
	}
	return (flags);
}

int	get_placeholder_width(char **fmt, va_list *ap, int *have_width)
{
	int	width;

	if (**fmt == '*')
	{
		*have_width = 1;
		(*fmt)++;
		return ((int)va_arg(*ap, int));
	}
	else
	{
		width = 0;
		while ((**fmt >= '0') && (**fmt <= '9'))
		{
			width = (width * 10) + (**fmt - '0');
			(*fmt)++;
		}
		if (width)
			*have_width = 1;
		return (width);
	}
}

int	get_placeholder_precision(char **fmt, va_list *ap, int *have_precision)
{
	int	precision;

	if (**fmt != '.')
		return (-1);
	(*fmt)++;
	*have_precision = 1;
	if (**fmt == '*')
	{
		(*fmt)++;
		return ((int)va_arg(*ap, int));
	}
	else
	{
		precision = 0;
		while ((**fmt >= '0') && (**fmt <= '9'))
		{
			precision = (precision * 10) + (**fmt - '0');
			(*fmt)++;
		}
		return (precision);
	}
}

int	get_placeholder_length(char **fmt)
{
	int	length;

	length = 0;
	if ((**fmt == 'h') && ((*(fmt))[1] == 'h'))
		length = sizeof(char) * CHAR_BIT;
	else if (**fmt == 'h')
		length = sizeof(short) * CHAR_BIT;
	else if ((**fmt == 'l') && ((*(fmt))[1] == 'l'))
		length = sizeof(long long) * CHAR_BIT;
	else if (**fmt == 'l')
		length = sizeof(long) * CHAR_BIT;
	else if (**fmt == 'j')
		length = sizeof(intmax_t) * CHAR_BIT;
	else if (**fmt == 't')
		length = sizeof(ptrdiff_t) * CHAR_BIT;
	else if (**fmt == 'z')
		length = sizeof(size_t) * CHAR_BIT;
	if ((**fmt == 'h') && ((*(fmt))[1] == 'h'))
		(*fmt)++;
	else if ((**fmt == 'l') && ((*(fmt))[1] == 'l'))
		(*fmt)++;
	if (length)
		(*fmt)++;
	return (length);
}
