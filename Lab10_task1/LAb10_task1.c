#include <stdio.h>
#include <locale.h>
#include <math.h>

double main()
{
	setlocale(LC_CTYPE, "rus");

	double x, y,y1;
	double fa(double x);
	double fb(double x);

	puts("Введите x:");
	scanf("%lg", &x);

	printf("\n fa(x) = %lg  fb(x) = %lg\n", fa(x),fb(x));
	printf("Произведение: %lg\nРазность квадратов: %lg\nУдвоенная сумма: %lg", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));
}

double fa(double x) {
	double y;
	if (x <= 3) y = pow(x, 2) - 3 * x + 9;
	else y = pow(pow(x, 3) + 3, -1);
	return y;
}

double fb(double x)
{
	double y1;

	y1 = x * exp(sin(pow(x, 2)));
	return y1;
}
