#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#include <math.h>

int main()
{
	int a;
	setlocale(LC_CTYPE, "RUS");
	puts("������� ����� ����� ����:");
	scanf_s("%d", &a);
	printf("����� ����: % g\n", pow(a,3));
	printf("������� ������� �����������: %g\n", pow(a,2)*6);
}