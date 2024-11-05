#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	float tabul, xmin=0.1,xmax=2.1000;
	float x = xmin;

	puts("Введите шаг табуляци для функции y=x^2 + sin5x:");
	scanf_s("%f", &tabul);
	printf("_______________________\n");
	printf("|    x     |   f(x)   |\n");
	printf("_______________________\n");
	while (x <= xmax)
	{
		printf("| %3f | %3f |\n",x, pow(x, 2) + sin(x * 5));
		printf("_______________________\n");
		x += tabul;
	}

}