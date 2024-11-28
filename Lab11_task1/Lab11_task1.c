#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 10

void main()
{
	setlocale(LC_CTYPE, "rus");

	float A[N];
    float temp, y=0.0;

    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }
    printf("Каждый элемент массива умножен на 2:\n");
    printf("| индекс | исходное значение | новое значение\n");
    for (int i1 = 0; i1 < 10; i1++)
    {
        printf("| %6d | %17.2f | %.2f\n", i1, A[i1], A[i1] * 2);

    }
    printf("\nНулевые элементы массива заменены их порядковым номером:\n");
    printf("| индекс | исходное значение | новое значение\n");
    for (int i2 = 0;i2 < 10;i2++)
    {
        float y=0;
        if (A[i2] != 0) y = A[i2];
        else y = i2;
        printf("| %6d | %17.2f | %.2f\n", i2, A[i2], y);
    }
    printf("\nСреднее арифмитическое элементов массива:\n");
    for (int i = 0;i < 10;i++)
    {
        y += A[i];
    }
    printf("%f", y/N);
}