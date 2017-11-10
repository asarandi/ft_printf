/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:29:06 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/09 21:06:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <locale.h>

int main()
{
    char *locale;

    locale = setlocale(LC_ALL, "");



	printf("0 printf %d\n",     printf("{%f}{%F}", 1444565444646.6465424242242, 1444565444646.6465424242242));
	printf("0 ftprnt %d\n",  ft_printf("{%f}{%F}", 1444565444646.6465424242242, 1444565444646.6465424242242));


//	printf(   "printf: {%015.6S}\n", L"家に大型ダンプ突っ込む…運転手死亡、住民無事");
//	ft_printf("ftprnt: {%015.6S}\n", L"家に大型ダンプ突っ込む…運転手死亡、住民無事");


/*
debug next:
	73 precision for cC
	01 conv s simple
	61 flag plus spec
*/


//debug next: {%3c} .. printf outputs 2 blank spaces
/// ft_printf outputs 3 blank spaces

/*
printf("%d\n",     printf("1 printf: {%#.o, %#.0o}\n", 0, 0));
printf("%d\n", ft_printf( "1 ftprnt: {%#.o, %#.0o}\n", 0, 0));

printf("%d\n",     printf("2 printf: {%#.o}\n", 0, 0));
printf("%d\n", ft_printf( "2 ftprnt: {%#.o}\n", 0, 0));

printf("%d\n",     printf("3 printf: {%#.0o}\n", 0, 0));
printf("%d\n", ft_printf( "3 ftprnt: {%#.0o}\n", 0, 0));

printf("%d\n",     printf("4 printf: {%05p}\n", 0));
printf("%d\n", ft_printf( "4 ftprnt: {%05p}\n", 0));

printf("%d\n",     printf("5 printf: {%.5p}\n", 0));
printf("%d\n", ft_printf( "5 ftprnt: {%.5p}\n", 0));
*/
//printf("%d\n",     printf("6 printf: {%d}\n", -2147483655));
//printf("%d\n", ft_printf( "6 ftprnt: {%d}\n", -2147483655));

//	printf("printf %d\n",    printf("%.5C", 0));
//	printf("ftprnt %d\n", ft_printf("%.5C", 0));
//	printf("printf {%lc}\n", L'品');
//	ft_printf("ft_printf {%lc}\n", L'品');


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

//ft_printf("%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);
//   printf("%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);

//ft_printf("%.4d\n", -42);
//   printf("%.4d\n", -42);



//ft_printf("%lld", -1);

//printf("hello%juworld\n", (uintmax_t) -1 );

//printf("size of int * CHAR_BIT %d\n", sizeof(int) * CHAR_BIT);
//printf("size of long long %d\n", sizeof(long long));

return (0);

}
