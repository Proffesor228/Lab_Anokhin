#include <stdio.h>
#include <math.h>
#include <locale.h>
#define ROW 9
#define COL 9

void main()
{
	setlocale(LC_CTYPE, "rus");

	int row, col;
	printf("\n");
	for (row = 1;row <= ROW;++row)
	{
		for (col = 1;col <= COL;++col)
			printf("%5d", col * row);
		printf("\n");
	}

	system("pause");

	int row1, col1, c = 1;
	printf("\n");
	for (row1 = 1;row1 <= ROW | c<=9;++row1,++c)
	{
		for (col1 = 1;col1 <= c;++col1)
			printf("%5d", col1 * row1);
		printf("\n");
	}
	system("pause");

	int row2,col2;
	printf("\n");
	for (row2 = 1;row2 <= ROW;++row2)
	{
		for (col2 = 1;col2 <= COL;++col2)
			printf("%5d",5);
		printf("\n");
	}
	system("pause");
}