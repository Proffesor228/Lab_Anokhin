#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	int x;
	setlocale(LC_CTYPE, "rus");

	puts("������� ����� ����� �� 10 �� 20:");
	scanf_s("%d", &x);
	switch (x)
	{
	case 10:
		printf("10 - ������");
		break;
	case 11:
		printf("11 - �����������");
		break;
	case 12:
		printf("12 - ����������");
		break;
	case 13:
		printf("13 - ����������");
		break;
	case 14:
		printf("14 - ������������");
		break;
	case 15:
		printf("15 - ����������");
		break;
	case 16:
		printf("16 - �����������");
		break;
	case 17:
		printf("17 - ����������");
		break;
	case 18:
		printf("18 - ������������");
		break;
	case 19:
		printf("19 - ������������");
		break;
	case 20:
		printf("20 - ��������");
		break;
	default:
		printf("������������ �����");
	}
	return 0;
}