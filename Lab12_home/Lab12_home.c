#include <locale.h>
#include <stdio.h>

#define SIZEOF(object) (char *)(&object+1) - (char *)(&object)

int main()
{
	setlocale(LC_CTYPE, "rus");

	char x2 = 'a';
	short int x3 = 123;
	unsigned short int x4 = 123;
	int x5 = 123;
	unsigned char x6 = 'a';
	wchar_t x7 = 'a';
	long long int x8 = 123;
	size_t x9 = 123;
	float x10 = 123.2;
	double x11 = 123.5;
	signed int x12 = 123;
	
	printf(" %ld\n %ld\n %ld\n %ld\n %ld\n %ld\n", SIZEOF(x2), SIZEOF(x3), SIZEOF(x4), SIZEOF(x5), SIZEOF(x6), SIZEOF(x7));
	printf(" %ld\n %ld\n %ld\n %ld\n %ld\n", SIZEOF(x8), SIZEOF(x9), SIZEOF(x10), SIZEOF(x11), SIZEOF(x12));
	
	int y = (char*)(&x2 + 1) - (char*)(&x2);
	printf("\n %d", y);
}
