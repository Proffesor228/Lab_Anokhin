#include <iostream>
#include <stdlib.h>
using namespace std;

long long int opred(int** matr,size_t size)
{
	int j = 0;
	long long int sum1 = 0, sum2 = 0, frst = 1;
	for (int g = 0; g < size; g++)
	{
		frst = 1;
		j = g;
		for (int i = 0; i < size; i++)
		{
			frst *= matr[i][j];
			j++;
			if (j == size) j = 0;
		}
	}
	for (int g = 0; g < size; g++)
	{
		frst = 1;
		j = size-1-g;
		for (int i = 0; i < size; i++)
		{
			frst *= matr[i][j];
			j--;
			if (j == -1) j = size - 1;
		}
	}
	if (size > 5) opred(matr, size - 1);
	return sum1 - sum2;
}
void translag(int** matr,size_t size)
{
	//transalg
	long long int** obrat = (long long int**)matr;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int** podop = matr;
			int fr = 0, sc = 0;
			int** minor = new int* [size - 1];
			for (size_t i = 0; i < size - 1; i++) minor[i] = new int[size - 1];
			for (int c = 0; c < size; c++) { podop[i][c] = 0; podop[c][j] = 0; }
			for (int g = 0; g < size; g++)
			{
				for (int h = 0; h < size; h++)
				{
					if (podop[g][h] != 0) { minor[fr][sc] = podop[g][h]; sc++; }
					if (sc > size - 1) { fr++; sc = 0; }
				}
			}
			obrat[i][j] = opred(minor, size - 1) * pow(-1, (i + 1) + (j + 1));
		}
	}
}
void main()
{
	system("chcp 1251");
	size_t size;
	int n = 0, ch = 1;
	cout << "Введите размер матрицы (>=4 и <=16): "; cin >> size;
	if (size < 4 || size >16) { cout << "\nРазмер не входит в диапазон!\n"; return; }

	int** matr = new int*[size];
	for (size_t i = 0; i < size; i++) matr[i] = new int[size];

	for (int j = 0; j < size; j++)
	{
		int size1 = size;
		if (j % 2 == 0) for (n; n < size; n++) { matr[j][n] = ch; ch += 1; }
		else {
			for (n; n < size; n++) { matr[j][size1-1] = ch; ch += 1; size1 -= 1; }
		}
		n = 0;
	}

	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++) { if (matr[j][i] < 10) cout << "  "; if (matr[j][i] >= 10&& matr[j][i] < 100) cout << " "; cout << " " << matr[j][i]; }
		cout << "\n";
	}
	cout << opred(matr, size);
}