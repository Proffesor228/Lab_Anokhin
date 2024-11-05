#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	setlocale(LC_CTYPE, "rus");

	char a;
	int d,x,y;

	puts("¬ведите используемый символ:");
	scanf("%c", &a);
	puts("¬ведите сторону квадрата:");
	scanf_s("%d", &d);

	for (x = 1;x <= d;++x)
	{
		printf("%2c",a);
		for (y = 3;y <= d;++y)
		{
			if (x == 1 || x == d) printf("%2c", a);
			else printf("%2c",' ');
		}
		if (d>1) printf("%2c\n",a);
	}
}