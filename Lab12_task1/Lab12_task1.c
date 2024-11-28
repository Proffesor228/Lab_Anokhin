#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_CTYPE, "rus");

	int* pi, i = 5;
	float* pf, f = 2.1f;
	char* pc, c = 'g';
	printf("%lu\n", sizeof(pi));
	printf("%lu\n", sizeof(pf));
	printf("%lu\n", sizeof(pc));
}