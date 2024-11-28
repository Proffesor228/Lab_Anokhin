#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	setlocale(LC_CTYPE, "rus");

	float A[100], x=0.1, y3=0.0;
	int y1=0, y2=0;
	for (int i =0;i < 100;i++,x += 0.020202)
	{
		A[i] = pow(x, 2) + sin(x * 5);
	}
	for (int i = 0;i < 100;i++)
	{
		if (A[i] < 0) y1 += 1;
		else y2 += 1;
	}
	for (int i = 0;i < 100;i++)
	{
		if (A[i] > 0) y3 += A[i];
	}
	printf("Имя массива: A, Кол-во полож. чисел: %d, Кол-во отриц. чисел: %d, Среднее полож. чисел: %f\n", y2, y1, y3/100);


	float B[100], x1 = 0.1, z3 = 0.0;
	int z1 = 0, z2 = 0;
	for (int i = 0;i < 100;i++, x1 += 0.020202)
	{
		B[i] = x*sin(x);
	}
	for (int i = 0;i < 100;i++)
	{
		if (B[i] < 0) z1 += 1;
		else z2 += 1;
	}
	for (int i = 0;i < 100;i++)
	{
		if (B[i] > 0) z3 += B[i];
	}
	printf("Имя массива: B, Кол-во полож. чисел: %d, Кол-во отриц. чисел: %d, Среднее полож. чисел: %f", z2, z1, z3/100);
}