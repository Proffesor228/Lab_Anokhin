#include <stdio.h>
#include <locale.h>

int main()
{
	int n;
	setlocale(LC_CTYPE, "rus");
	puts("Введите целое трёхзначное число:\n");
	scanf_s("%d",&n);
	printf("1) Первая цифра числа: %d\n", n / 100);
	printf("2) Последняя цифра числа: %d\n", n % 10);
	printf("3) Сумма цифр числа: %d", ((n / 10) % 10)+n/100+n%10);

}