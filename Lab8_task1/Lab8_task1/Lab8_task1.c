#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	int s=0, n, m, k=0;

	puts("������� ������� �����:");
	scanf_s("%d", &n);
	puts("������� ������� �����:");
	scanf_s("%d", &m);

	for (int i = m;i >= n;i--)
	{
		s += i;
		printf("��������� %d ���\n", k++);
	}
	printf("��������� %d", s);
}