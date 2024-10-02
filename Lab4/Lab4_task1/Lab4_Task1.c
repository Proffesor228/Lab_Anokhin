#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");
	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;
	printf("%c, %d, %g, %lg\n", c, i, f, d);

	char c1;
	int i1;
	float f1;
	double d1;
	puts("Введите символ:");
	scanf_s("%c", &c1);
	puts("Введите целое число:");
	scanf_s("%d", &i1);
	puts("Введите число с дестичной дробью:");
	scanf_s("%g", &f1);
	puts("Введите любое число:");
	scanf_s("%lg", &d1);

	printf("Целая часть: %d ", (int)f1);
	printf("Дробная часть: %2g\n", f1-(int)f1);

	printf("Символ в шестнадцатеричной системе: %x\n", c1);
	printf("Символ в десятичной системе: %i\n", c1);
	printf("Десятичное число, соотвествующее 1/i: %g", (double)1/i1);
}