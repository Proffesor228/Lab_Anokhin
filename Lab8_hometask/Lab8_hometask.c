#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	float a, x;

	puts("������� �������� a:");
	scanf_s("%f", &a);
	puts("������� �������� x:");
	scanf_s("%f", &x);

	printf("%.2f^%.2f = %.4f", a, x, pow(a, x));
}