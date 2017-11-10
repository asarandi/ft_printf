#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <wchar.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <locale.h>
# include "libftprintf.h"


int main()
{

	wchar_t	*wide = L"До́брый ве́чер";

       	printf("pf {%S}\n", wide);
	ft_printf("ft {%S}\n", wide);

//   	printf("printf: %#o\n", 1230);
//	ft_printf("ft_printf: {%%} alex  %#o\n", 1230);

/*
printf("\n1 %.4d", -42);
ft_printf("\n1 %.4d\n", -42);

printf("\n2 {%10d}", -42);
ft_printf("\n2 {%10d}\n", -42);

printf("\n3 {%*d}", -5, 42);
ft_printf("\n3 {%*d}\n", -5, 42);

printf("\n4 A%hhdA", CHAR_MIN - 42);
ft_printf("\n4 B%hhdB\n", CHAR_MIN - 42);

printf("\n5 %#o", 0);
ft_printf("\n5 %#o\n", 0);

printf("\n6 %#.o, %#.0o", 0, 0);
ft_printf("\n6 %#.o, %#.0o\n", 0, 0);


//7 A0, 65535B
//7 B0, -1B


   printf("\n7 A%hD, %hDA",   0, USHRT_MAX);
ft_printf("\n7 B%hD, %hDB\n", 0, USHRT_MAX);

   printf("\n7.2 A%hd, %hdA",   0, USHRT_MAX);
ft_printf("\n7.2 B%hd, %hdB\n", 0, USHRT_MAX);


   printf("\n7.3 A%hhD, %hhDA",   0, USHRT_MAX);
ft_printf("\n7.3 B%hhD, %hhDB\n", 0, USHRT_MAX);




printf("\n8 {%03c}", 0);
ft_printf("\n8 {%03c}\n", 0);

printf("\n9 %.4o", 42);
ft_printf("\n9 %.4o\n", 42);

printf("\n10 %*.*d", 0, 3, 0);
ft_printf("\n10 %*.*d\n", 0, 3, 0);

//   printf("\n11 A%.0pA, A%.pA", 0, 0);
//ft_printf("\n11 B%.0pB, B%.pB\n", 0, 0);

printf("\n12 %.4s", "42");
ft_printf("\n12 %.4s\n", "42");

//printf("\n13 A% dA", -9999);
//ft_printf("\n13 B% dB\n", -9999);

printf("\n14 {%03.2d}", 0);
ft_printf("\n14 {%03.2d}\n", 0);

*/


printf("\n");
}
