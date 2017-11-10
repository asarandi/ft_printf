/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:50:49 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/09 02:24:29 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	string_prefix(t_placeholder *ph, char *prefix)
{
	int	i;
	char	*memory;

	i = ft_strlen((char *)(*ph).output) + ft_strlen(prefix);
	memory = (char *)ft_memalloc(i + 1);
	if (memory == NULL)
	{
		free((*ph).output);
		(*ph).output = NULL;
		return ;
	}
	i = ft_strlen(prefix);
	(*ph).char_count += i;
	ft_strcpy(memory, prefix);
	ft_strcpy(&memory[i], (char *)(*ph).output);
	free((*ph).output);
	(*ph).output = (unsigned char *) memory;
	return ;
}

void	string_suffix(t_placeholder *ph, char *suffix)
{
	int	i;
	char	*memory;

	i = ft_strlen((char *)(*ph).output) + ft_strlen(suffix);
	memory = (char *)ft_memalloc(i + 1);
	if (memory == NULL)
	{
		free((*ph).output);
		(*ph).output = NULL;
		return ;
	}
	(*ph).char_count += ft_strlen(suffix);
	i = ft_strlen((char *)(*ph).output);
	ft_strcpy(memory, (char *)(*ph).output);
	ft_strcpy(&memory[i], suffix);
	free((*ph).output);
	(*ph).output = (unsigned char *) memory;
}
