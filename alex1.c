#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>

int main()
{
	intmax_t a =  -7;

	printf("%ld\n", a);


	uintmax_t b = -7;
	printf("%lu\n", b);


}
