#include <stdio.h>
#include <locale.h>

int main()
{
	int n;
	setlocale(LC_CTYPE, "rus");
	puts("������� ����� ���������� �����:\n");
	scanf_s("%d",&n);
	printf("1) ������ ����� �����: %d\n", n / 100);
	printf("2) ��������� ����� �����: %d\n", n % 10);
	printf("3) ����� ���� �����: %d", ((n / 10) % 10)+n/100+n%10);

}