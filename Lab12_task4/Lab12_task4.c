#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_CTYPE, "rus");

	float array[10] = { 1.1, 2.2, 3.3, 4.4,5.5,6.6,7.7,8.8,9.9,10.10 };
	float* ptr_a;

	printf("%p %p %p\n", array, &array[0], &array);
	ptr_a = &array[0];
	printf("\nАдрес:%p  Значение:%f\n", ptr_a, *ptr_a);
	ptr_a++;
	printf("Адрес:%p  Значение:%f\n", ptr_a, *ptr_a);
	ptr_a += 4;
	printf("Адрес:%p  Значение:%f\n", ptr_a, *ptr_a);
	ptr_a -= 2;
	printf("Адрес:%p  Значение:%f\n\n", ptr_a, *ptr_a);
	ptr_a = &array[0];
	for (int i = 0;i < 5;i++)
	{
		printf("Адрес: % p  Значение : % f\n", ptr_a, *ptr_a);
		ptr_a += 2;
	}
	ptr_a = &array[9];
	for (int i = 0;i < 5;i++)
	{
		printf("Адрес: % p  Значение : % f\n", ptr_a, *ptr_a);
		ptr_a -= 2;
	}
}