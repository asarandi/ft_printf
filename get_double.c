/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:01:00 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/12 03:27:29 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int		double_check_nan(double *d, t_placeholder *ph)
{
	if (*d < (double)0)
	{
		(*ph).sign = '-';
		*d = (-*d);

	}
	else
		(*ph).sign = '+';
	if (*d != *d)
	{
		(*ph).float_suffix = ft_strdup("nan");
		(*ph).float_prefix = ft_memalloc(1);
		(*ph).char_count = 3;
		return (1);
	}
	if ((*d == (double)1 / 0) || (*d == (double)-1 / 0))
	{
		(*ph).float_suffix = ft_strdup("inf");
		(*ph).float_prefix = ft_memalloc(1);
		(*ph).char_count = 3;
		return (1);
	}
	return (0);
}

void	get_double(va_list *ap, t_placeholder *ph)
{
	double		d;
	uintmax_t	prefix;
	uintmax_t	suffix;
	double		decimals;

	d = va_arg(*ap, double);
	if (double_check_nan(&d, ph))
		return ;
	prefix = (uintmax_t)d;
	decimals = ((d - (double)prefix) * 1000000000000000000);
	suffix = (uintmax_t)(decimals);
	decimals = 0;
	while (1)
	{
		while ((suffix) && ((suffix % 10) == 0))
		{
			suffix /= 10;
			decimals += 1;
		}
		while (suffix % 10 >= 5)
			suffix++;
		if (suffix % 10 != 0)
			break ;
	}
	(*ph).float_prefix = float_itoa(prefix);
	(*ph).float_suffix = float_suffix(suffix, 18 - decimals);
}

void	float_cosmetics(t_placeholder *ph)
{
	if ((*ph).sign == '-')
		string_prefix(ph, "-");
	if (((*ph).flags & FLAG_PLUS) && ((*ph).sign == '+'))
		string_prefix(ph, "+");
	if ((*ph).type == 'F')
		ft_strtoupper((char *)(*ph).output);
}

void	format_double(t_placeholder *ph)
{
	(*ph).output = (unsigned char *)(*ph).float_suffix;
	if (((*ph).output[0] != 'n') && ((*ph).output[0] != 'i'))
	{
		if ((*ph).have_precision == 0)
		{
			if (ft_strlen((char *)(*ph).output) > 6)
				(*ph).output[6] = 0;
			while (ft_strlen((char *)(*ph).output) < 6)
				string_suffix(ph, "0");
		}
		(*ph).char_count = ft_strlen((char *)(*ph).output);
		add_precision(ph);
		string_prefix(ph, ".");
		string_prefix(ph, (*ph).float_prefix);
	}
	free((*ph).float_prefix);
	float_cosmetics(ph);
	add_width(ph);
}
