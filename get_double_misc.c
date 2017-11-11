/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:01:00 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/10 15:56:27 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				is_digit(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int				is_deprecated(char type)
{
	if ((type == 'D') || (type == 'O') || (type == 'U'))
		return (1);
	return (0);
}

int				digits_before_point(uintmax_t n)
{
	int	r;

	if (n == 0)
		return (1);
	r = 0;
	while (n)
	{
		r++;
		n /= 10;
	}
	return (r);
}

unsigned char	*get_double(va_list *ap, t_placeholder *ph)
{
	double		n;
	uintmax_t	prefix;
	uintmax_t	suffix;
	double		decimals;

	(*ph).sign = '+';
	n = va_arg(*ap, double);
	if (n < 0)
	{
		n = (-n);
		(*ph).sign = '-';
	}
	prefix = (uintmax_t)n;
	decimals = ((n - (double)prefix) * 1000000000000000000) + 100;
	suffix = (uintmax_t)decimals;
	while ((suffix) && ((suffix % 10) == 0))
		suffix /= 10;
	(*ph).float_prefix = float_itoa(prefix);
	(*ph).float_suffix = float_itoa(suffix);
	return (NULL);
}

void			make_non_numeric(t_placeholder *ph, va_list *ap)
{
	if ((*ph).type == 's')
		(*ph).output = get_string(ap, ph);
	else if ((*ph).type == 'S')
		(*ph).output = get_wide_string(ap, ph);
	else if ((*ph).type == 'C')
		(*ph).output = get_wchar(ap, ph);
	else if ((*ph).type == 'c')
		(*ph).output = get_char(ap, ph);
	else if (((*ph).type == 'f') || ((*ph).type == 'F'))
		(*ph).output = get_double(ap, ph);
	else
	{
		(*ph).invalid = 1;
		(*ph).output = ft_memalloc(2);
		(*ph).output[0] = (*ph).type;
		(*ph).char_count = 1;
	}
}
