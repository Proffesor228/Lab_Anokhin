#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	setlocale(LC_CTYPE, "rus");

	long d,n=1,x=1,s=0,s1=0,s2=0,k=0;
	char a;

	puts("Введите произвольное длинное число:");
	scanf_s("%d", &d);

	while (x != 0) 
	{
		x = (d / n) % 10;
		s += x;
		if (x % 2 == 0) s1 += x;
		else s2 += x;
		if (x == 3) k += 1;
		n = n * 10;
		printf("Продолжить ? (Да - y, нет - n)");
		scanf("%c", &a);
		if ((a = getchar()) == 'n') break;
	}
	printf("Кол-во цифр 3: %d\n", k);
	printf("Сумма всех цифр: %d\n", s);
	printf("Сумма чётных цифр: %d\n", s1);
	printf("Сумма нечётных цифр: %d\n", s2);
	printf("Произведение сумм цифр: %d\n", s*s1*s2);
}