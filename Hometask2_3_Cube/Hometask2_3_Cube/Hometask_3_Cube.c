#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#include <math.h>

int main()
{
	int a;
	setlocale(LC_CTYPE, "RUS");
	puts("¬ведите длину грани куба:");
	scanf_s("%d", &a);
	printf("ќбьЄм куба: % g\n", pow(a,3));
	printf("площадь боковой поверхности: %g\n", pow(a,2)*6);
}