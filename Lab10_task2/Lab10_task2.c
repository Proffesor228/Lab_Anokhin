#include <stdio.h>
#include <locale.h>
#include <math.h>

double main()
{
	setlocale(LC_CTYPE, "rus");

	double eps,x, y1, y2, y3;
	int N=9;
	double fa(double x);
	double fb(double x, int N);
	double fc(double x, int eps);
	long int fact(long int k);

	puts("Введите x:");
	scanf("%lg", &x);
	puts("Введите точность ряда Маклорена:");
	scanf("%lg", &eps);
	printf("  N | %10s | отклонение\n\n", "e^(-x)");
	printf("1)%lg\n  2)%lg\n  3)%lg\n", fa(x), fb(x,N),fc(x,eps));

}
double fa(double x)
{
	double y1;
	y1 = sin(x);
	return y1;
}
double fb(double x, int N)
{
	double y2;
	int n1,k;
	for (n1=0,k=1,y2=0;n1 < N;n1++,k++) {
		y2 += pow(-1, k - 1) * (pow(x, 2 * k - 1) / fact(2 * k - 1));
	}
	return y2;
}
double fc(double x, int eps) 
{
	double y3;
	int k;
	for ( k = 0, y3 = 0;k < eps; k++) {
		y3 += pow(-1,k)*(pow(x,k)/fact(k));
		printf(" %2d | %10.4lg | %lg\n", k, y3, exp(-x) - y3);
	}
	return y3;
}
long int fact(long int k)
{
	if (k == 0) return 1;
	return k * fact(k - 1);
}