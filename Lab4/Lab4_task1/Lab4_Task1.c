#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");
	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;
	printf("%c, %d, %g, %lg\n", c, i, f, d);

	char c1;
	int i1;
	float f1;
	double d1;
	puts("������� ������:");
	scanf_s("%c", &c1);
	puts("������� ����� �����:");
	scanf_s("%d", &i1);
	puts("������� ����� � ��������� ������:");
	scanf_s("%g", &f1);
	puts("������� ����� �����:");
	scanf_s("%lg", &d1);

	printf("����� �����: %d ", (int)f1);
	printf("������� �����: %2g\n", f1-(int)f1);

	printf("������ � ����������������� �������: %x\n", c1);
	printf("������ � ���������� �������: %i\n", c1);
	printf("���������� �����, �������������� 1/i: %g", (double)1/i1);
}