#include <locale.h>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	float PI = 3.14159, * p1, * p2;

	p1 = p2 = &PI;

	printf("�� ������ p1=%p �������� *p1=%g\n", p1, *p1);
	printf("�� ������ p2=%p �������� *p2=%g\n", p2, *p2);
	printf("�� ������ p1=%x �������� *p1=%g\n", p1, *p1);
	printf("�� ������ p2=%x �������� *p2=%g\n", p2, *p2);
}