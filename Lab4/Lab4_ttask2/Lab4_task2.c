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
	puts("Вывод: При выражении с двумя переменными типа int, итоговое значение оставется int вне зависимости от того,\n какому типу переменной оно присваивается");

	printf("float: %f\n", (float)a / b);
	printf("double: %g\n", (double)a / b);
	puts("Вывод: При выражениях с переменными типа int, следует использовать явные преобразования для более точного результата,\n если результат отличается от переменных по типу");
}