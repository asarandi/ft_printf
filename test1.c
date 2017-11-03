/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:29:06 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/03 02:07:49 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main()
{

//ft_printf("number1 %0#159.678d", 123456);
//char	*c = "Hello World";
//printf("%s\n", c);
//unsigned char z = 0x65;
//
//printf("%jd\n", (uintmax_t) INT32_MIN);

char *mem = print_octohex(817236817263871, 64, 8);
printf("%s\n", mem);
free(mem);

printf("%-d\n", -1231);

return (0);

}
