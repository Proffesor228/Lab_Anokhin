#include <stdio.h>
#include <locale.h>

int main()

{
	setlocale(LC_CTYPE, "rus");

	int c;
	char c1;

	printf("������� ����� ��� �����: ");
	if ((scanf_s("%d", &c))==1) printf("��� �����\n"); // ����������� ���-�� ����� �������� ��������
	else printf("��� �����\n");

}