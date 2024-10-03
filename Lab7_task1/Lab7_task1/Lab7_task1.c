#include <stdio.h>
#include <locale.h>

int main()

{
	setlocale(LC_CTYPE, "rus");

	int c;
	char c1;

	printf("¬ведите букву или цифру: ");
	if ((scanf_s("%d", &c))==1) printf("Ёто цифра\n"); // определение кол-ва верно введЄнных значений
	else printf("Ёто буква\n");

}