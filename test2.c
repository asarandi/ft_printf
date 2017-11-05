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
	printf("|%#05o|\n", 5);
	printf("%06x\n", -8);
	printf("%015u\n", -8);
	printf("%012i\n", -8);
	printf("%06d\n", -8);
	printf("%06d\n", -8);
	printf("%06d\n", -8);
	printf("%06d\n", -8);
	printf("char %C\n", 68);

/*	wchar_t myc;
    myc	= L'Ω';
	write(1, &myc, sizeof(wchar_t));
*/
	wchar_t *kanji = L"部首ぶしゅ";
//	unsigned int x;
//	x = kanji[0];


//	wchar_t kan = '部';

//	char conv[100];
//	int i = 0;
//	while (i < 100)
//		conv[i++] = 0;
//	setlocale(LC_ALL, "UTF-8");	
	setlocale(LC_ALL, "");


       printf("   printf: %ls \n", L"Δκαιοπολις εν αγρω εστιν");
    ft_printf("ft_printf: %S  \n", L"Δκαιοπολις εν αγρω εστιν");




//	wprintf(L"%s\n", L"ο Δικαιοπολις εν αγρω εστιν");
//	printf("\nwctomb returns: %d\n", wctomb(&conv[0], (wchar_t) L"部"));
//	write(1, &conv[0], 1);


	printf("test W %S\n", kanji);
	printf("test X %s\n", (char *)kanji);
	write(1, "米", sizeof(wchar_t));
	write(1, "\n", 1);
	write(1, &kanji[0], sizeof(wchar_t));








}
