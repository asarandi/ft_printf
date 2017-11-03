/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 01:26:48 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/03 01:50:51 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

uintmax_t	trim_bits(uintmax_t n, int number_of_bits)
{
	if (number_of_bits == 8)
		return (n & UINT8_MAX);
	if (number_of_bits == 16)
		return (n & UINT16_MAX);
	if (number_of_bits == 32)
		return (n & UINT32_MAX);
	if (number_of_bits == 64)
		return (n & UINT64_MAX);
	return (0);
}

int			check_negative(uintmax_t *n, int number_of_bits, int signedness)
{
	int negative;

	if (signedness == 0)
		return (0);
	negative = 0;
	if ((number_of_bits == 8) && (*n > INT8_MAX))
		negative = 1;
	if ((number_of_bits == 16) && (*n > INT16_MAX))
		negative = 1;
	if ((number_of_bits == 32) && (*n > INT32_MAX))
		negative = 1;
	if ((number_of_bits == 64) && (*n > INT64_MAX))
		negative = 1;
	*n = negative ? -*n : *n;
	return (negative);
}

char		*print_decimal(uintmax_t n, int number_of_bits, int signedness)
{
	int		negative;
	int		i;
	char	buffer[32];
	char	*result;

	negative = check_negative(&n, number_of_bits, signedness);
	n = trim_bits(n, number_of_bits);
	i = 31;
	buffer[i--] = 0;
	if (n == 0)
		buffer[i--] = '0';
	while (n)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
		buffer[i--] = '-';
	i++;
	result = ft_memalloc(ft_strlen(&buffer[i]) + 1);
	if (result == NULL)
		return (NULL);
	return (ft_memcpy(result, &buffer[i], ft_strlen(&buffer[i])));
}

char		*print_octohex(uintmax_t n, int number_of_bits, int base)
{
	const char	*hex_table = "0123456789abcdef";
	int			i;
	char		buffer[32];
	char		*result;

	n = trim_bits(n, number_of_bits);
	i = 31;
	buffer[i--] = 0;
	if (n == 0)
		buffer[i--] = '0';
	while (n)
	{
		buffer[i--] = hex_table[n % base];
		n /= base;
	}
	i++;
	result = ft_memalloc(ft_strlen(&buffer[i]) + 1);
	if (result == NULL)
		return (NULL);
	return (ft_memcpy(result, &buffer[i], ft_strlen(&buffer[i])));
}
