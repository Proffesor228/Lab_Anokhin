#include <locale.h>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	int *pa, x = 5;

	pa = &x;
	
	printf("По адресу %p хранится *ptr=%g\n", pa,*pa );
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa,*pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa,*pa);


	double* pb, x1 = 5.3;

	pb = &x1;

	printf("\nПо адресу %p хранится *ptr=%g\n", pb, *pb);
	pb++;
	printf("По адресу %p хранится *ptr=%g\n", pb, *pb);
	pb--;
	printf("По адресу %p хранится *ptr=%g\n", pb, *pb);


	char* pc, x2 = 5;

	pc = &x2;

	printf("\nПо адресу %p хранится *ptr=%g\n", pc, *pc);
	pc++;
	printf("По адресу %p хранится *ptr=%g\n", pc, *pc);
	pc--;
	printf("По адресу %p хранится *ptr=%g\n", pc, *pc);
}