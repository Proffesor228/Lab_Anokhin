#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_CTYPE, "rus");

	float array[10] = { 1.1, 2.2, 3.3, 4.4,5.5,6.6,7.7,8.8,9.9,10.10 };
	float* ptr_a;

	printf("%p %p %p\n", array, &array[0], &array);
	ptr_a = &array[0];
	printf("\n�����:%p  ��������:%f\n", ptr_a, *ptr_a);
	ptr_a++;
	printf("�����:%p  ��������:%f\n", ptr_a, *ptr_a);
	ptr_a += 4;
	printf("�����:%p  ��������:%f\n", ptr_a, *ptr_a);
	ptr_a -= 2;
	printf("�����:%p  ��������:%f\n\n", ptr_a, *ptr_a);
	ptr_a = &array[0];
	for (int i = 0;i < 5;i++)
	{
		printf("�����: % p  �������� : % f\n", ptr_a, *ptr_a);
		ptr_a += 2;
	}
	ptr_a = &array[9];
	for (int i = 0;i < 5;i++)
	{
		printf("�����: % p  �������� : % f\n", ptr_a, *ptr_a);
		ptr_a -= 2;
	}
}