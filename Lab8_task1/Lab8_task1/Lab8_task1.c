#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	int s=0, n, m, k=0;

	puts("Введите меньшее число:");
	scanf_s("%d", &n);
	puts("Введите большее число:");
	scanf_s("%d", &m);

	for (int i = m;i >= n;i--)
	{
		s += i;
		printf("Выполнено %d раз\n", k++);
	}
	printf("результат %d", s);
}