/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso8601.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:06:01 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/14 01:00:12 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	iso_time(uintmax_t t)
{
	int			leaps;
	int			is_leap;
	int			day;
	const int	months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			mo;

	leaps = 0;
	is_leap = 0;
	if ((t / 31536000) >= 2)
		leaps = ((t / 31536000) + 2) / 4;
	if (((t / 31536000) + 2) % 4 == 0)
		is_leap = 1;
	day = ((t / 86400) - (leaps - is_leap)) % 365;
	day += 1;
	mo = 0;
	while (day > months[mo])
	{
		day -= months[mo++];
		if ((is_leap) && (mo == 1))
			day -= 1;
	}
	leaps = (leaps - is_leap) * 86400;
	ft_printf("%d-%02d-%02d", ((t - leaps) / 31536000) + 1970, ++mo, day);
	ft_printf("T%02d:%02d:%02d+00:00", t / 3600 % 24, t / 60 % 60, t % 60);
}
