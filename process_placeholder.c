/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_placeholder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:55:33 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/01 17:11:41 by asarandi         ###   ########.fr       */
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
		if (**fmt == '+')
			flags |= B00000001;
		else if (**fmt == '-')
			flags |= B00000010;
		else if (**fmt == ' ')
			flags |= B00000100;
		else if (**fmt == '#')
			flags |= B00001000;
		else if (**fmt == '0')
			flags |= B00010000;
		else
			return (flags);
		(*fmt)++;
	}
	return (flags);
}

int	get_placeholder_width(char **fmt, va_list *ap)
{
	int	width;

	if (**fmt == '*')
	{
		(*fmt)++;
		return((int) va_arg(*ap, int));
	}
	else
	{
		width = 0;
		while ((**fmt >= '0') && (**fmt <= '9'))
		{
			width = (width * 10) + (**fmt - '0');
			(*fmt)++;
		}
		return (width);
	}
}

int	get_placeholder_precision(char **fmt, va_list *ap)
{
	int	precision;

	if (**fmt != '.')
		return (0);
	(*fmt)++;
	if (**fmt == '*')
	{
		(*fmt)++;
		return((int) va_arg(*ap, int));
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
