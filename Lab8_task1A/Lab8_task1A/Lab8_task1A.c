#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	int s = 0, n, m, k=0;
	float f;

	puts("¬ведите меньшее число:");
	scanf_s("%d", &n);
	puts("¬ведите большее число:");
	scanf_s("%d", &m);

	for (int i = n;i <= m;i++)
	{
		s = pow(2, i);
		printf("2^%d = %d\n", i,s);
		k += s;
	}
	f = (float)k / 1024;
	if (k >= 1024) printf("–езультат: %.1fK\n", (float)f);
	else printf("–езультат: %d\n", k);
}