#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	float x, y;
	char c;
	setlocale(LC_CTYPE, "rus");

	puts("������� ���������:");
	scanf("%f%c%f", &x,&c,&y);
	switch (c)
	{
	case '+':
		printf("=%.4f", x + y);
		break;
	case '-':
		printf("=%.4f", x - y);
		break;
	case '*':
		printf("=%.4f", x * y);
		break;
	case '/':
		printf("=%.4f", x / y);
		break;
	case '^':
		printf("=%.4f", pow(x,y));
		break;
	default:
		printf("����������� ���������");
	}
	return 0;
}