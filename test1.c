/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:29:06 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/04 03:55:38 by asarandi         ###   ########.fr       */
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

//char *mem = print_octohex(0xff, 8, 8);
//printf("%s\n", mem);
//free(mem);




/*
ft_printf("%010d  %#08x %p\n", 12345, 666, &ft_printf);
   printf("%010d  %#08x %p\n", 12345, 666, &ft_printf);
ft_printf("%zd%zd\n", 0, 42);
   printf("%zd%zd\n", 0, 42);

ft_printf("%hhd%hhd\n", 1, 42);
   printf("%hhd%hhd\n", 1, 42);
*/
ft_printf("%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);
   printf("%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);

ft_printf("%.4d\n", -42);
   printf("%.4d\n", -42);



//ft_printf("%lld", -1);

//printf("hello%juworld\n", (uintmax_t) -1 );

//printf("size of int * CHAR_BIT %d\n", sizeof(int) * CHAR_BIT);
//printf("size of long long %d\n", sizeof(long long));

return (0);

}
