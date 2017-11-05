#include <unistd.h>
#include <wchar.h>

int		wchar_to_utf8(unsigned int wchar, unsigned char *output)
{
		if ((wchar > 0x7F) && (wchar <= 0x7FF))
		{
			output[0] = ((wchar >> 6) & 0x1F) + 0xC0;
			output[1] = (wchar & 0x3F) + 0x80;
			return (2);
		}
		else if ((wchar > 0x7FF) && (wchar <= 0xFFFF))
		{
			output[0] = ((wchar >> 12) & 0xF) + 0xE0;
			output[1] = ((wchar >> 6) & 0x3F) + 0x80;
			output[2] = (wchar & 0x3F) + 0x80;
			return (3);
		}
		else if ((wchar > 0xFFFF) && (wchar <= 0x1FFFFF))
		{
			output[0] = ((wchar >> 18) & 0x7) + 0xF0;
			output[1] = ((wchar >> 12) & 0x3F) + 0x80;
			output[2] = ((wchar >> 6) & 0x3F) + 0x80;
			output[3] = (wchar & 0x3F) + 0x80;
			return (4);
		}
		output[0] = wchar & 0x7F;
		return (1);
}

int main()
{

	wchar_t	*wide = L"До́брый ве́чер";
//	wchar_t	*wide = L"常用漢字";
	wint_t	i;
	unsigned int r;

	i = 0;
	unsigned char out[4];
	int number_utf8_bytes;
	while (wide[i])
	{
		r = wide[i++];
		number_utf8_bytes = wchar_to_utf8(r, out);
		write(1, &out, number_utf8_bytes);
	}
	write(1, "\n", 1);



	unsigned char	a[4] = {0xf0, 0x90, 0x8d, 0x88};
	write(1, &a, 4);

	write(1, "\n", 1);
	return (0);
}
