/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:29:06 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/03 18:37:14 by asarandi         ###   ########.fr       */
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

char *mem = print_octohex(0xff, 8, 8);
printf("%s\n", mem);
free(mem);


ft_printf("%hu", (short) -1);
//ft_printf("%lld", -1);

//printf("hello%juworld\n", (uintmax_t) -1 );

//printf("size of int * CHAR_BIT %d\n", sizeof(int) * CHAR_BIT);
//printf("size of long long %d\n", sizeof(long long));

return (0);

}
