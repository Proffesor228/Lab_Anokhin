#include <locale.h>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	float PI = 3.14159, * p1, * p2;

	p1 = p2 = &PI;

	printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);
	printf("По адресу p1=%x хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=%x хранится *p2=%g\n", p2, *p2);
}