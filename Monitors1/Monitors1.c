#include <stdio.h>
#include <string.h>
#include <locale.h>

void main()
{
	setlocale(LC_CTYPE, "rus");
	FILE* fl;
	fl = fopen("monitors.bin", "ab+");
	char ans = 'y';
	char kl[40];
	char name[8][20] = { "Название: ","Производитель: ","Диагональ: ","Разрешение: ","Матрица: ","Изогнутый экран: ","Разъём HDMI: " };
	int num, i = 0,num1;
	int sort[50],sort1[50];
	char dev[50][20];
	char poz[15];
	int first = 0;
	struct monitors
	{
		char name[50];
		char dev[50];
		char diag[50];
		char razr[50];
		char matr[50];
		char izog[50];
		char razh[50];
	}st[30];
	fread(&st, sizeof(st), 1, fl);
	fread(&i, sizeof(i), 1, fl);
	fread(&sort, sizeof(sort), 1, fl);
	fclose(fl);
	while (ans == 'y')
	{
		printf("Выберите нужное действие:\n1)Создать новую запись\n2)Поиск записи\n3)Вывести базу данных\n4)Сортировать по производителю\n5)Изменить запись\n6)Добавить несколько записей\n7)Сохранить данные\n");
		scanf("%d", &num);
		if (num > 7 || num < 1) printf("\nНужное действие не обнаружено\n");
		switch (num)
		{
		case 1:
			printf("Введите название:");
			scanf("%s", st[i].name);
			printf("Производитель: ");
			scanf("%s", st[i].dev);
			sort[i] = i;
			printf("Диагональ: ");
			scanf("%s", st[i].diag);
			printf("Разрешение: ");
			scanf("%s", st[i].razr);
			printf("Матрица: ");
			scanf("%s", st[i].matr);
			printf("Изогнутый экран: ");
			scanf("%s", st[i].izog);
			printf("Разъём HDMI: ");
			scanf("%s", st[i].razh);
			i++;
			break;
		case 2:
			printf("Поле для поиска:\n1) Матрица\n2) Диагональ в см или дюймах\n3) По матрице и диагонали");
			scanf("%d", &num);
			switch (num)
			{
			case 1:
				printf("Введите ключ: ");
				scanf("%s", kl);
				for (int j = 0;j < i;j++)
				{
					if (strstr(st[j].matr, kl) != NULL) printf("\n%s%30s %s%10s %s%8s %s%10s %s%5s %s%3s %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
				}
				break;
			case 2:
				printf("Введите ключ:\n1)В см\n2)В дюймах\n");
				scanf("%d", &num1);
				switch (num1)
				{
				case 1:
					for (int j = 0;j < i;j++)
					{
						if (strstr(st[j].diag, "sm") != NULL) printf("\n%s%30s %s%10s %s%8s %s%10s %s%5s %s%3s %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
					}
					break;
				case 2:
					for (int j = 0;j < i;j++)
					{
						if (strstr(st[j].diag, "\"") != NULL) printf("\n%s%30s %s%10s %s%8s %s%10s %s%5s %s%3s %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
					}
					break;
				default:
					printf("\nЗаписей не найдено");
					break;
				}
				break;
			case 3:
				printf("Введите ключ для матрицы: \n");
				scanf("%s", kl);
				printf("Введите ключ для диагонали:\n1)В см\n2)В дюймах\n");
				scanf("%d", &num1);
				switch (num1)
				{
				case 1:
					for (int j = 0;j < i;j++)
					{
						if (strstr(st[j].diag, "sm") != NULL) if (strstr(st[j].matr, kl) != NULL) printf("\n%s%30s %s%10s %s%8s %s%10s %s%5s %s%3s %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
					}
					break;
				case 2:
					for (int j = 0;j < i;j++)
					{
						if (strstr(st[j].diag, "\"") != NULL) if (strstr(st[j].matr, kl) != NULL) printf("\n%s%30s %s%10s %s%8s %s%10s %s%5s %s%3s %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
					}
					break;
				default:
					printf("\nЗаписей не найдено");
					break;
				}
			}
			break;
		case 3:
			for (int j = 0;j < i;j++)
			{
				printf("\n%s%30s %s%10s %s%8s %s%10s %s%5s %s%3s %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
			}
			break;
		case 4:
			for (int z = 0;z < i;z++)
			{
				sort1[z] = sort[z];
			}
			for (int z = 0;z < i;z++)
			{
				strcpy(dev[z],st[z].dev);
			}
			for (int j = 0;j < i;j++)
			{
				int result = strcmp(dev[j],dev[j+1]);
				if (result > 0) {
					first = sort1[j];
					sort1[j] = sort1[j+1];
					sort1[j + 1] = first;
					strcpy(poz, dev[j]);
					strcpy(dev[j], dev[j + 1]);
					strcpy(dev[j + 1], poz);
					j = -1;
				}
			}
			for (int m = 0; m < i; m++)
			{
				printf("\n%s%30s %s%10s %s%8s %s%10s %s%5s %s%3s %s%4s", name[0], st[sort1[m]].name, name[1], st[sort1[m]].dev, name[2], st[sort1[m]].diag, name[3], st[sort1[m]].razr, name[4], st[sort1[m]].matr, name[5], st[sort1[m]].izog, name[6], st[sort1[m]].razh);
			}
			break;
		case 5:
			printf("Введите номер записи:");
			scanf("%d", &num1);
			printf("Введите название:");
			scanf("%s", st[num1-1].name);
			printf("Производитель: ");
			scanf("%s", st[num1-1].dev);
			printf("Диагональ: ");
			scanf("%s", st[num1-1].diag);
			printf("Разрешение: ");
			scanf("%s", st[num1-1].razr);
			printf("Матрица: ");
			scanf("%s", st[num1-1].matr);
			printf("Изогнутый экран: ");
			scanf("%s", st[num1-1].izog);
			printf("Разъём HDMI: ");
			scanf("%s", st[num1-1].razh);
			break;
		case 6:
			printf("Сколько записей добавить?\n");
			scanf("%d", &num1);
			for (int j = 0;j < num1;j++)
			{
				printf("Введите название:");
				scanf("%s", st[i].name);
				printf("Производитель: ");
				scanf("%s", st[i].dev);
				sort[i] = i;
				printf("Диагональ: ");
				scanf("%s", st[i].diag);
				printf("Разрешение: ");
				scanf("%s", st[i].razr);
				printf("Матрица: ");
				scanf("%s", st[i].matr);
				printf("Изогнутый экран: ");
				scanf("%s", st[i].izog);
				printf("Разъём HDMI: ");
				scanf("%s", st[i].razh);
				i++;
			}
			break;
		case 7:
			fl = fopen("monitors.bin", "wb+");
			fwrite(&st, sizeof(st), 1, fl);
			fwrite(&i, sizeof(i), 1, fl);
			fwrite(&sort, sizeof(sort), 1, fl);
			printf("\nДанные сохранены\n");
			break;
		}
		getchar();
		printf("\nПродолжить? (y-да,n-нет)\n");
		scanf("%c", &ans);
	}
}