#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	int y, a, n1,vib;
	char c = '*';
	int fig(int a);

	setlocale(LC_CTYPE, "rus");
	printf("Введите количество сторон фигуры, возможные фигуры: 4 - квадрат\n");
	scanf_s("%d", &a);
	y = fig(a);
	switch (y)
	{
	case 3:
		printf("Выберите нужное действие:\n 1) рассчитать площадь\n 2) вывести определение фигуры\n 3) нарисовать фигуру\n");
		scanf_s("%d", &vib);
		switch (vib)
		{
		case 1:
			printf("Введите сторону квадрата:\n");
			scanf_s("%d", &n1);
			area_kvad(n1);
			break;
		case 2:
			fig(a);
			break;
		case 3:
			printf("Введите сторону квадрата:\n");
			scanf_s("%d", &n1);
			draw_kvad(n1, c);
		}
	}
}
int fig(int a)
{
	int y;
	switch (a)
	{
	case 4:
		printf("Выбранная фигура: квадрат\n");
		return y = 3;
	default:
		printf("Неподходящее число\n");
	}
}
int draw_kvad(int n1, char c)
{
	int x, x1;
	for (x = 1;x <= n1;++x)
	{
		printf("%2c", c);
		for (x1 = 3;x1 <= n1;++x1)
		{
			if (x == 1 || x == n1) printf("%2c", c);
			else printf("%2c", ' ');
		}
		if (n1 > 1) printf("%2c\n", c);
	}
}
int area_kvad(int n1)
{
	printf("Площадь квадрата: %d", (int)pow(n1, 2));
}