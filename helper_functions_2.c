/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:50:49 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/04 03:50:53 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*printf_string_prefix(char *string, char *prefix)
{
	int	i;
	char	*memory;

	i = ft_strlen(string) + ft_strlen(prefix);
	memory = (char *)ft_memalloc(i + 1);
	if (memory == NULL)
		return (NULL);
	i = ft_strlen(prefix);
	ft_memcpy(memory, prefix, i);
	ft_memcpy(&memory[i], string, ft_strlen(string));
	free(string);
	return (memory);
}

char	*printf_string_suffix(char *string, char *suffix)
{
	int	i;
	char	*memory;

	i = ft_strlen(string) + ft_strlen(suffix);
	memory = (char *)ft_memalloc(i + 1);
	if (memory == NULL)
		return (NULL);
	i = ft_strlen(string);
	ft_memcpy(memory, string, i);
	ft_memcpy(&memory[i], suffix, ft_strlen(suffix));
	free(string);
	return (memory);
}