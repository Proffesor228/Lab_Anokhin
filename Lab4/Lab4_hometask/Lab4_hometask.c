#include <stdio.h>
#include <locale.h>

int main()
{
	int x;
	int a;

	setlocale(LC_CTYPE, "rus");

	puts("Введите стоимость молока за 1л:");
	scanf_s("%d", &x);
	puts("Введите наценку на молоко в апреле:");
	scanf_s("%d", &a);

	printf("Нужно заплатить за молоко за март и апрель %d", x * 31 * 4 + (x + a) * 30 * 4);
}