#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
	char Snew[40] = "Good morning, ", Name[20];
	printf("Your name:\n");
	scanf("%s", Name);
	strcat(Snew, Name);
	printf("%s!\n", Snew);
	for (int i = 0; Snew[i] != '\0'; i++)
	{
		putchar(toupper(Snew[i]));
	}
	puts("!");
	for (int i = 0; i<40; i++)
	{
		if (Snew[i] == '\0') printf("!");
		else putchar(Snew[i]);
	}
}