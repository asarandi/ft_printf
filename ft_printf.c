/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:21:32 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/03 17:24:25 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"


int	printf_is_numeric(char *fmt)
{
	if ((*fmt == 'p') || (*fmt == 'd') || (*fmt == 'D') || (*fmt == 'i'))
		return (1);
	else if ((*fmt == 'o') || (*fmt == 'O') || (*fmt == 'u'))
		return (1);
	else if ((*fmt == 'U') || (*fmt == 'x') || (*fmt == 'X'))
		return (1);
	else
		return (0);
}

int	printf_get_default_length(char *fmt)
{
	if ((*fmt == 'd') || (*fmt == 'o') || (*fmt == 'u'))
		return (sizeof(int) * CHAR_BIT);
	else if ((*fmt == 'i') || (*fmt == 'x') || (*fmt == 'X'))
		return (sizeof(int) * CHAR_BIT);
	else if ((*fmt == 'D') || (*fmt == 'O') || (*fmt == 'U'))
		return (sizeof(long) * CHAR_BIT);
	else if (*fmt == 'p')
		return (sizeof(ptrdiff_t) * CHAR_BIT);
	else
		return (0);
}

int	printf_is_signed(char *fmt)
{
	if ((*fmt == 'd') || (*fmt == 'D') || (*fmt == 'i'))
		return (1);
	else
		return (0);
}

int	printf_is_decimal(char *fmt)
{
	if ((*fmt == 'd') || (*fmt == 'D') || (*fmt == 'i'))
		return (1);
	else if ((*fmt == 'u') || (*fmt == 'U'))
		return (1);
	else
		return (0);
}

int	printf_get_base(char *fmt)
{
	if ((*fmt == 'd') || (*fmt == 'D') || (*fmt == 'i'))
		return (10);
	else if ((*fmt == 'u') || (*fmt == 'U'))
		return (10);
	else if ((*fmt == 'o') || (*fmt == 'O'))
		return (8);
	else if ((*fmt == 'x') || (*fmt == 'X') || (*fmt == 'p'))
		return (16);
	else
		return (0);
}

int	ft_printf(const char *restrict format, ...)
{
	unsigned long long int	x;
	char	*fmt;
	va_list	ap;

	va_start(ap, format);
		while (*format)
		{ 
			while ((*format) && (*format != '%'))
				write(1, format++, 1);
			if (*format == '%')
			{
				if (*(format + 1) == '%')
					write(1, '%', 1);
				else
				{	
					fmt = (char *)format;
					int flags = get_placeholder_flags(&fmt);
			        int width = get_placeholder_width(&fmt, &ap);
					int precision = get_placeholder_precision(&fmt, &ap);
					int length = get_placeholder_length(&fmt);
					char *output;
					uintmax_t	n;
					if ((*fmt == 'd') || (*fmt == 'i'))
					{
						n = (uintmax_t)va_arg(*ap, int);
						if (length == 0)
							length = sizeof(int) * CHAR_BIT;
						output = print_decimal(n, length, 1);
					}
					else if (*fmt == 'D')
					{
						n = (uintmax_t)va_arg(*ap, long);
						if (length == 0)
							length = sizeof(long) * CHAR_BIT;
						output = print_decimal(n, length, 1);
					}
					else if (*fmt == 'o')
					{
						n = (uintmax_t)va_arg(*ap, unsigned int);
						if (length == 0)
							length = sizeof(unsigned int) * CHAR_BIT;
						output = print_octohex(n, length, 8);
					}
					else if (*fmt == 'O')
					{
						n = (uintmax_t)va_arg(*ap, unsigned long);
						if (length == 0)
							length = sizeof(unsigned long) * CHAR_BIT;
						output = print_octohex(n, length, 8);
					}
					else if (*fmt == 'u')
					{
						n = (uintmax_t)va_arg(*ap, unsigned int);
						if (length == 0)
							length = sizeof(unsigned int) * CHAR_BIT;
						output = print_decimal(n, length, 0);
					}
					else if (*fmt == 'U')
					{
						n = (uintmax_t)va_arg(*ap, unsigned long);
						if (length == 0)
							length = sizeof(unsigned long) * CHAR_BIT;
						output = print_decimal(n, length, 0);
					}
					else if ((*fmt == 'x') || (*fmt == 'X'))
					{
						n = (uintmax_t)va_arg(*ap, unsigned int);
						if (length == 0)
							length = sizeof(unsigned int) * CHAR_BIT;
						output = print_octohex(n, 
					}

						




				}
			}
		}
}
