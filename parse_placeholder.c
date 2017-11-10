/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_placeholder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:55:33 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/07 23:48:44 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_placeholder_flags(char **fmt, t_placeholder *placeholder)
{
	if (**fmt == '%')
		(*fmt)++;
	while (**fmt)
	{
		if (**fmt == '#')
			(*placeholder).flags |= FLAG_HASHTAG;
		else if (**fmt == '0')
			(*placeholder).flags |= FLAG_ZERO;
		else if (**fmt == '-')
			(*placeholder).flags |= FLAG_MINUS;
		else if (**fmt == ' ')
			(*placeholder).flags |= FLAG_SPACE;
		else if (**fmt == '+')
			(*placeholder).flags |= FLAG_PLUS;
		else
			break ;
		(*fmt)++;
	}
	if ((*placeholder).flags)
		(*placeholder).have_flags = 1;
	return ;
}

void	get_placeholder_width(char **fmt, va_list *ap, t_placeholder *ph)
{
	if (**fmt == '*')
	{
		(*ph).have_width = 1;
		(*fmt)++;
		(*ph).width = (int)va_arg(*ap, int);
		return ;
	}
	else
	{
		while ((**fmt >= '0') && (**fmt <= '9'))
		{
			(*ph).width = ((*ph).width * 10) + (**fmt - '0');
			(*fmt)++;
		}
		if ((*ph).width)
			(*ph).have_width = 1;
	}
	return ;
}

void	get_placeholder_precision(char **fmt, va_list *ap, t_placeholder *ph)
{
	if (**fmt != '.')
		return ;
	(*fmt)++;
	(*ph).have_precision = 1;
	if (**fmt == '*')
	{
		(*fmt)++;
		(*ph).precision = (int)va_arg(*ap, int);
	}
	else
	{
		while ((**fmt >= '0') && (**fmt <= '9'))
		{
			(*ph).precision = ((*ph).precision * 10) + (**fmt - '0');
			(*fmt)++;
		}
	}
	return ;
}

void	get_placeholder_length(char **fmt, t_placeholder *placeholder)
{
	if ((**fmt == 'h') && ((*(fmt))[1] == 'h'))
		(*placeholder).length = sizeof(char) * CHAR_BIT;
	else if (**fmt == 'h')
		(*placeholder).length = sizeof(short) * CHAR_BIT;
	else if ((**fmt == 'l') && ((*(fmt))[1] == 'l'))
		(*placeholder).length = sizeof(long long) * CHAR_BIT;
	else if (**fmt == 'l')
		(*placeholder).length = sizeof(long) * CHAR_BIT;
	else if (**fmt == 'j')
		(*placeholder).length = sizeof(intmax_t) * CHAR_BIT;
	else if (**fmt == 't')
		(*placeholder).length = sizeof(ptrdiff_t) * CHAR_BIT;
	else if (**fmt == 'z')
		(*placeholder).length = sizeof(size_t) * CHAR_BIT;
	if ((**fmt == 'h') && ((*(fmt))[1] == 'h'))
		(*fmt)++;
	else if ((**fmt == 'l') && ((*(fmt))[1] == 'l'))
		(*fmt)++;
	if ((*placeholder).length)
		(*fmt)++;
	return ;
}
