/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:01:00 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/11 19:36:43 by asarandi         ###   ########.fr       */
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


char	*float_suffix(uintmax_t n, int digits)
{
	int			i;
	char		buffer[32];

	i = 31;
	buffer[i--] = 0;
	if (n == 0)
		buffer[i--] = '0';
	while (digits--)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (ft_strdup(&buffer[i]));
}



unsigned char	*get_double(va_list *ap, t_placeholder *ph)
{
	double		n;
	uintmax_t	prefix;
	uintmax_t	suffix;
//	double		decimals;

	(*ph).sign = '+';
	n = va_arg(*ap, double);
	if (n < 0)
	{
		n = (-n);
		(*ph).sign = '-';
	}
	int dap = 0;
	prefix = (uintmax_t) n;
	double copy = (double)prefix;
	suffix = prefix;
	uintmax_t suf2 = 0;
	while (n - copy != 0)
	{
		n *= 10.0;
		copy = (double)suffix * (double)10.0;
		suffix *= 10;
		suffix += (uintmax_t) (n - copy);
		suf2 *= 10;
		suf2 += (uintmax_t) (n - copy);
		dap++;
		if (dap >= 19)
			break ;
	}
	(*ph).float_prefix = float_itoa(prefix);
	(*ph).float_suffix = float_suffix(suf2, dap);
	return (NULL);
}

void			other_formats(t_placeholder *ph, va_list *ap)
{
	if	((*ph).type == 'k')
	{
		iso_time((uintmax_t)va_arg(*ap, uintmax_t));
		(*ph).output = ft_memalloc(1);
		(*ph).char_count = ft_strlen("2017-11-11T20:26:43+00:00");
	}
	else
	{
		(*ph).invalid = 1;
		(*ph).output = ft_memalloc(2);
		(*ph).output[0] = (*ph).type;
		(*ph).char_count = 1;
	}

}

void			make_non_numeric(t_placeholder *ph, va_list *ap)
{
	int	*n_ptr;

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
	else if ((*ph).type == 'n')
	{
		n_ptr = (int *)va_arg(*ap, int *);
		*n_ptr = (*ph).written;
		(*ph).output = ft_memalloc(1);
	}
	else
		other_formats(ph, ap);
}
