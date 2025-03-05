#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int task1()
{
	double e1, e2, f1 = 0, f2 = 0, x;
	int sr1=0, sr2=0;
	cout << "Введите аргумент x (|x| < 1): "; cin >> x;
	cout << "Введите точность e1: "; cin >> e1;
	cout << "Введите точность e2: "; cin >> e2;

	double sum1 = -(e1) * 10, sum2 = -(e2) * 10;
	cout << "\nФункция (-1)^k * (k + 1)*x^k\n\n";

	cout << "|  Аргумент  |     f1(x)     |  Точность1  |     f2(x)     |  Точность2  |\n";
	for (int k = 0; abs(f2 - sum2) > e2; k++)
	{
		if (abs(f1 - sum1) > e1) {
			sum1 = f1;
			f1 += pow(-1, k) * (k + 1) * pow(x, k);
			printf("|%12lf|%15lf|%13lf", x, f1, e1);
			sr1 += 1;
		}
		else cout << "|            |               |             ";
		sum2 = f2;
		f2 += pow(-1, k) * (k + 1) * pow(x, k);
		printf("|%15lf|%13lf|\n", f2, e2);
		sr2 += 1;
	}
	cout << "Скорость сходимости ряда f1: " << sr1 << "\nСкорость сходимости ряда f2: " << sr2;
	return 0;
}
void task2()
{
	double a;
	cout << "Введите число для кубического корня: "; cin >> a;
	double sum = a / 3.0;
	while (abs(pow(a, 1.0 / 3) - sum) >= 0.000001)
	{
		sum = (2.0 / 3) * (sum + (a / (2 * pow(sum, 2))));
	}
	cout << "\nКорень кубический из " << a << ": " << sum << "\n";
}
void main()
{
	system("chcp 1251");
	task2();
}