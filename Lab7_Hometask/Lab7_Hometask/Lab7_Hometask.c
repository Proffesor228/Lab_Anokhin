#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	int x;
	setlocale(LC_CTYPE, "rus");

	puts("Введите целое число от 10 до 20:");
	scanf_s("%d", &x);
	switch (x)
	{
	case 10:
		printf("10 - десять");
		break;
	case 11:
		printf("11 - одиннадцать");
		break;
	case 12:
		printf("12 - двенадцать");
		break;
	case 13:
		printf("13 - тринадцать");
		break;
	case 14:
		printf("14 - четырнадцать");
		break;
	case 15:
		printf("15 - пятнадцать");
		break;
	case 16:
		printf("16 - шестнадцать");
		break;
	case 17:
		printf("17 - семнадцать");
		break;
	case 18:
		printf("18 - восемнадцать");
		break;
	case 19:
		printf("19 - девятнадцать");
		break;
	case 20:
		printf("20 - двадцать");
		break;
	default:
		printf("Неподходящее число");
	}
	return 0;
}