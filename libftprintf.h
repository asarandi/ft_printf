/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:37:11 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/01 17:09:36 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "ft_binary_byte.h"

int	get_placeholder_flags(char **fmt);
int	get_placeholder_width(char **fmt, va_list *ap);
int	get_placeholder_precision(char **fmt, va_list *ap);
int	ft_printf(const char *restrict format, ...);


#endif
