#include <locale.h>
#include <stdio.h>
void date()
{
	puts("____  ____   ____  ____   ____  ____");
	puts("|  |  |  |   |  |  |___   |  |  |___");
	puts("  /   |  |   |  |     |   |  |  |  |");
	puts(" /__  |__| . |__|  ___| . |__|  |__|");
}
void name()
{
	puts("*******************************************");
	puts("*                                         *");
	puts("* тема: Разработка консольного приложения *");
	puts("*                                         *");
	puts("*   Выполнил: Анохин А. О.                *");
	puts("*                                         *");
	puts("*******************************************");
}
void main()
{

	setlocale(LC_CTYPE, "RUS");
	puts("Нажмите Enter");
	getchar();
	name();
	getchar();
	date();
}