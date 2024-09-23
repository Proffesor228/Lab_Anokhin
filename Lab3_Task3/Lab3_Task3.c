#include <locale.h>
#include <stdio.h>

int main()
{
	int a, b;
	setlocale(LC_ALL, "RUS");
	puts("Введите a и b");
	scanf("%d %d", &a, &b);
	printf("________________________\n");
	printf("|a*b\t|a+b\t|a-b\t|\n");
	printf("________________________\n");
	printf("|%d*%d\t|%d+%d\t|%d-%d\t|\n", a, b, a, b, a, b);
	printf("________________________\n");
	printf("|%d\t|%d\t|%d\t|\n", a * b, a + b, a - b);
	printf("________________________\n");
}