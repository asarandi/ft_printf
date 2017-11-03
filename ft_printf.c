/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:21:32 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/02 19:03:07 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	ft_printf(const char *restrict format, ...)
{
	unsigned long long int	x;
	char	*fmt;
	va_list	ap;

	va_start(ap, format);
		while (*format)
		{ 
			while ((*format) && (*format != '%'))
				format++;
			fmt = (char *)format;
			printf("    flags: %d\n",get_placeholder_flags(&fmt));
			printf("    width: %d\n",get_placeholder_width(&fmt, &ap));
			printf("precision: %d\n",get_placeholder_precision(&fmt, &ap));
			format++;

		}
		printf("\n%ld\n", 184073709551615);

	return (0);
}
