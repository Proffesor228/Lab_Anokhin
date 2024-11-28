#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define N 10

void main()
{
	setlocale(LC_CTYPE, "rus");

	int A[N],temp,y=0,sum=0,y1=1;

    for (int i = 0; i < 10; i++)

    {
        printf("a[%d] = ", i + 1);
        scanf_s("%d", &temp);
        if (i == 0) y = temp;
        if (i != 0) if (temp == y) y1 += 1;
        if (i != 0) if(A[i-1]>temp) if(temp!=y) y = temp, y1 = 1;
        sum += temp;
        A[i] = temp;
    }
    printf("\n%d %d %d\n", y1,y,sum);
    printf("Среднее арифм. массива, кроме мин. значения: %f", (float)(((float)sum-(float)y*(float)y1)/(10.0-(float)y1)));
}