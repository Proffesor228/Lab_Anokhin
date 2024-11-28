#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
	char str[40];
	int k = 0,c=0;
	printf("Enter your string:\n");

	fgets(str, 40,stdin);
	for (int i = 0;str[i] == ' ';i++) k++;
	c = k;
	for (int i = k;str[i] != ' ' && str[i] != '\t' && str[i] != '\n';i++) c++;
	for (k;k <= c;k++) putchar(str[k]);
}