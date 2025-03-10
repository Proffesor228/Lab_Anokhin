#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void task1()
{
	size_t size;
	int n = 0, sum = 0, num = 0;
	cout << "Введите размер массива: "; cin >> size;
	if (size < 1) { cout << "\nРазмер неверный!\n"; return; }
	int* matr = new int[size];
	int* pol = new int[size];

	srand(time(NULL));
	cout << "Массив случайных чисел: \n";
	for (int i = 0; i < size; i++)
	{
		matr[i] = rand() - 15000;
		if (i == 0) num = matr[i];
		else if (matr[i] < num) num = matr[i];
		sum += matr[i];
		if (matr[i] > 0) { pol[n] = matr[i]; n++; }

		if (i % 10 == 0 && i != 0) cout << "\n";
		printf("%8d", matr[i]);
	}
	cout << "\nНаименьшее число: " << num << "\nСумма чисел: " << sum;
	cout << "\nВсе положительные числа:\n";
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0 && i != 0) cout << "\n";
		printf("%8d", pol[i]);
	}
	cout << "\n";
}
void task2()
{
	size_t size;
	int matr[6][5];
	int pol[6];
	int n = 0;

	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "matr[" << j << "][" << i << "] = "; cin >> matr[j][i];
		}
	}
	for (int j = 0; j < 6; j++)
	{
		bool is = 0;
		for (int i = 0; i < 5; i++)
		{
			if (matr[j][i] % 2 == 0) { pol[n] = matr[j][i]; is = 1; break; }
		}
		if (is == 0) pol[n] = 0;
		n++;
	}
	for (int i = 0; i < 6; i++) cout << pol[i] << " ";
	cout << "\n";
}
void task3()
{
	size_t size;
	int n = 0;
	cout << "Введите размер массива: "; cin >> size;
	if (size < 1) { cout << "\nРазмер неверный!\n"; return; }
	int* matr = new int[size];
	for (int i = 0; i < size; i++) { cout << "matr[" << i << "] = "; cin >> matr[i]; }
	cout << "Массив чисел:\n";
	for (int i = 0; i < size; i++) cout << matr[i] << " ";
	cout << "\nОтсортированный массив чисел:\n";
	for (int i = size - 1; i != 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (matr[j] > matr[j + 1]) { n = matr[j + 1]; matr[j + 1] = matr[j]; matr[j] = n; }
		}
	}
	for (int i = 0; i < size; i++) cout << matr[i] << " ";
}

void main()
{
	system("chcp 1251");
	task1();
	task2();
	task3();
}
