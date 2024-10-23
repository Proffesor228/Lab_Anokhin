#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	int k;
	short ca;
	setlocale(LC_CTYPE, "rus");
	puts("Введите нужное количество символов:");
	scanf_s("%d", &k);
	puts("Введите нужный символ:");
	scanf("%s", &ca);

	for (int start = 1; start <= k; start++) printf("%c!",ca);
}