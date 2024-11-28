#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
	char Snew[40] = "Good morning, ", Name[40];
	printf("Your name:\n");

	scanf("%s", Name);
	printf("%s%c%c%s!\n", Snew, Name[0], Name[0], Name);
	strcat(Snew, Name);
	int k = (int)strlen(Snew);
	printf("%s%c!\n", Snew,Snew[k-1]);

}