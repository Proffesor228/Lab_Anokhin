#include <stdio.h>
#include <locale.h>

int main()
{
	int x;
	int a;

	setlocale(LC_CTYPE, "rus");

	puts("������� ��������� ������ �� 1�:");
	scanf_s("%d", &x);
	puts("������� ������� �� ������ � ������:");
	scanf_s("%d", &a);

	printf("����� ��������� �� ������ �� ���� � ������ %d", x * 31 * 4 + (x + a) * 30 * 4);
}