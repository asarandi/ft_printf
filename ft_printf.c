/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:21:32 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/04 03:42:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	ft_printf(const char *restrict format, ...)
{
	char	*fmt;
	char	*output;
	va_list	ap;

	int	count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{ 
			while ((*format) && (*format != '%'))
			{
				write(1, format++, 1);
				count++;
			}
			if (*format == '%')
			{
				if (*(format + 1) == '%')
				{
					write(1, "%", 1);
					count++;
				}
				else
				{	
					fmt = (char *)format;
					int flags = get_placeholder_flags(&fmt);
				        int width = get_placeholder_width(&fmt, &ap);
					int precision = get_placeholder_precision(&fmt, &ap);
					int length = get_placeholder_length(&fmt);
					if (length == 0)
						length = printf_get_default_length(fmt);

					uintmax_t	n;
					if (printf_is_numeric(fmt))
					{
						char sign[] = "+";

						n = (uintmax_t)va_arg(ap, uintmax_t);
						if (printf_is_decimal(fmt))
							output = print_decimal(n, length, printf_is_signed(fmt), &sign[0]);
						else
							output = print_octohex(n, length, printf_get_base(fmt));

						if (flags & FLAG_ZERO) // FLAG_ZERO is cleared if precision is set, or FLAG_MINUS
						{
							if ((precision) || (flags & FLAG_MINUS))
								flags ^= 1 << 1;
						}
						if ((flags & FLAG_SPACE) && (flags & FLAG_PLUS)) //FLAG_SPACE is cleared if FLAG_PLUS is set
							flags ^= 1 << 3;

						if (*fmt == 'p')
							flags |= 1 << 0; //FLAG_HASHTAG for type 'p'

						if (width > (int) ft_strlen(output)) //// width
						{
							if (printf_is_signed(fmt))
							{
								if ((flags & FLAG_PLUS) || (*sign == '-'))
									width--;
								if ((flags & FLAG_SPACE) && (*sign == '+'))
									width--;
							}
							if ((flags & FLAG_HASHTAG) && ((*fmt == 'x') || (*fmt == 'X')))
								width -= 2;
							if ((flags & FLAG_HASHTAG) && ((*fmt == 'o') || (*fmt == 'O')))
								width--;
							if (flags & FLAG_ZERO)
							{
								while (width > (int) ft_strlen(output))
									output = printf_string_prefix(output, "0");
							}
							if (flags & FLAG_MINUS) //FLAG MINUS
							{
								while (width > (int) ft_strlen(output))
									output = printf_string_suffix(output, " ");
							}
						}
						
						if ((flags & FLAG_HASHTAG) && ((*fmt == 'x') || (*fmt == 'X') || (*fmt == 'p')))
							output = printf_string_prefix(output, "0x");
						
						if (*fmt == 'X')
							output = ft_strtoupper(output);
						
						if ((flags & FLAG_HASHTAG) && ((*fmt == 'o') || (*fmt == 'O')))
							output = printf_string_prefix(output, "0");
						
						if (((flags & FLAG_PLUS) && (printf_is_signed(fmt))) || (*sign == '-'))
							output = printf_string_prefix(output, sign);
						if ((flags & FLAG_SPACE) && (printf_is_signed(fmt)))
							output = printf_string_prefix(output, " ");
						while (width > (int) ft_strlen(output))
							output = printf_string_prefix(output, " ");

					}
						write(1, output, ft_strlen(output));
						count += ft_strlen(output);
						free(output);
						fmt++;
						format = fmt;
				}
			}
		}
		va_end(ap);
		return (count);

}
