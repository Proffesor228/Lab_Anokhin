#include <locale.h>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	int *pa, x = 5;

	pa = &x;
	
	printf("�� ������ %p �������� *ptr=%g\n", pa,*pa );
	pa++;
	printf("�� ������ %p �������� *ptr=%g\n", pa,*pa);
	pa--;
	printf("�� ������ %p �������� *ptr=%g\n", pa,*pa);


	double* pb, x1 = 5.3;

	pb = &x1;

	printf("\n�� ������ %p �������� *ptr=%g\n", pb, *pb);
	pb++;
	printf("�� ������ %p �������� *ptr=%g\n", pb, *pb);
	pb--;
	printf("�� ������ %p �������� *ptr=%g\n", pb, *pb);


	char* pc, x2 = 5;

	pc = &x2;

	printf("\n�� ������ %p �������� *ptr=%g\n", pc, *pc);
	pc++;
	printf("�� ������ %p �������� *ptr=%g\n", pc, *pc);
	pc--;
	printf("�� ������ %p �������� *ptr=%g\n", pc, *pc);
}