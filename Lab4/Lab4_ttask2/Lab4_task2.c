#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");
	int a = 11;
	int b = 3;
	int x = a / b;
	float y = a / b;
	double z = a / b;
	printf("x = %d\n", x);
	printf("y = %f\n", y);
	printf("z = %g\n", z);
	puts("�����: ��� ��������� � ����� ����������� ���� int, �������� �������� ��������� int ��� ����������� �� ����,\n ������ ���� ���������� ��� �������������");

	printf("float: %f\n", (float)a / b);
	printf("double: %g\n", (double)a / b);
	puts("�����: ��� ���������� � ����������� ���� int, ������� ������������ ����� �������������� ��� ����� ������� ����������,\n ���� ��������� ���������� �� ���������� �� ����");
}