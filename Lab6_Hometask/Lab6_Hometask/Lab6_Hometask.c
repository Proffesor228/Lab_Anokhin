#include <stdio.h>
#include <Locale.h>
#include <math.h>

float main()
{
	float x, y, c;
	setlocale(LC_CTYPE, "rus");
	puts("¬ведите x:");
	scanf_s("%f", &x);
	puts("¬ведите y:");
	scanf_s("%f", &y);

	if ((pow(x, 2) + pow(y, 2)) < (pow(y, 3) - 2 * pow(x, 2))) c = (pow(x, 2) + pow(y, 2));
	else c = (pow(y, 3) - 2 * pow(x, 2));
	printf("min(x^2 + y^2, y^3 - 2*x^2)-4 = %f", c-4);
}