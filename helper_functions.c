/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:50:34 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/04 03:50:37 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
