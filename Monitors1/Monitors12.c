#include <stdio.h>
#include <string.h>
#include <locale.h>
typedef struct monitors
{
	char name[50];
	char dev[50];
	char diag[50];
	char razr[50];
	char matr[50];
	char izog[50];
	char razh[50];
} moni_t;
void main()
{
	setlocale(LC_CTYPE, "rus");
	FILE* fl;
	fl = fopen("monitors.bin", "ab+");
	char ans = 'y';
	char kl[40];
	char name[8][20] = { "Name: ","Manufacturer: ","Diagonal: ","Resolution: ","Matrix: ","Curved screen: ","HDMI connector: " };
	int num, i = 0,num1;
	int sort[50],sort1[50];
	char dev[50][20];
	char poz[15];
	int first = 0;
	moni_t st[30];
	fread(&st, sizeof(st), 1, fl);
	fread(&i, sizeof(i), 1, fl);
	fread(&sort, sizeof(sort), 1, fl);
	fclose(fl);
	while (ans == 'y')
	{
		printf("Select the desired action:\n1)Create a new record\n2)Search for a record\n3)Display database\n4)Sort by manufacturer\n5)Edit record\n6)Add multiple records\n7)Save data\n");
		scanf("%d", &num);
		if (num > 7 || num < 1) printf("\nThe required action was not found.\n");
		switch (num)
		{
		case 1:
			input_moni(st, i);
			add(sort, i);
			i++;
			printf("%d  %d", i, sort[i]);
			break;
		case 2:
			printf("Search field:\n1) Matrix\n2) Diagonal in cm or inches\n3) By matrix and diagonal");
			scanf("%d", &num);
			switch (num)
			{
			case 1:
				printf("Enter the key:");
				scanf("%s", kl);
				for (int j = 0;j < i;j++)
				{
					if (strstr(st[j].matr, kl) != NULL) printf("\n%s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
				}
				break;
			case 2:
				printf("Enter the key:\n1)In cm\n2)In inches\n");
				scanf("%d", &num1);
				switch (num1)
				{
				case 1:
					for (int j = 0;j < i;j++)
					{
						if (strstr(st[j].diag, "cm") != NULL) printf("\n%s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
					}
					break;
				case 2:
					for (int j = 0;j < i;j++)
					{
						if (strstr(st[j].diag, "\"") != NULL) printf("\n%s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
					}
					break;
				default:
					printf("\nNo records found");
					break;
				}
				break;
			case 3:
				printf("Enter the key for the matrix: \n");
				scanf("%s", kl);
				printf("Enter the key for diagonal:\n1)In cm\n2)In inches\n");
				scanf("%d", &num1);
				switch (num1)
				{
				case 1:
					for (int j = 0;j < i;j++)
					{
						if (strstr(st[j].diag, "sm") != NULL) if (strstr(st[j].matr, kl) != NULL) printf("\n%s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
					}
					break;
				case 2:
					for (int j = 0;j < i;j++)
					{
						if (strstr(st[j].diag, "\"") != NULL) if (strstr(st[j].matr, kl) != NULL) printf("\n%s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
					}
					break;
				default:
					printf("\nNo records found");
					break;
				}
			}
			break;
		case 3:
			for (int j = 0;j < i;j++)
			{
				printf("\n%s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
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
				printf("\n%s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", name[0], st[sort1[m]].name, name[1], st[sort1[m]].dev, name[2], st[sort1[m]].diag, name[3], st[sort1[m]].razr, name[4], st[sort1[m]].matr, name[5], st[sort1[m]].izog, name[6], st[sort1[m]].razh);
			}
			break;
		case 5:
			printf("Enter the entry number: ");
			scanf("%d", &num1);
			printf("Enter the name: ");
			scanf("%s", st[num1-1].name);
			printf("Manufacturer: ");
			scanf("%s", st[num1-1].dev);
			printf("Diagonal: ");
			scanf("%s", st[num1-1].diag);
			printf("Permission: ");
			scanf("%s", st[num1-1].razr);
			printf("Matrix: ");
			scanf("%s", st[num1-1].matr);
			printf("Curved screen: ");
			scanf("%s", st[num1-1].izog);
			printf("HDMI connector: ");
			scanf("%s", st[num1-1].razh);
			break;
		case 6:
			printf("How many records add?\n");
			scanf("%d", &num1);
			for (int j = 0;j < num1;j++)
			{
				input_moni(st, i);
				sort[i] = i;
				i++;
			}
			break;
		case 7:
			fl = fopen("monitors.bin", "wb+");
			fwrite(&st, sizeof(st), 1, fl);
			fwrite(&i, sizeof(i), 1, fl);
			fwrite(&sort, sizeof(sort), 1, fl);
			printf("\nData saved succesfully\n");
			break;
		}
		getchar();
		printf("\nContinue? (y-yes,n-no)\n");
		scanf("%c", &ans);
	}
}

moni_t input_moni(moni_t *st,int k) {
	struct moni_t;
	printf("Name: ");
	scanf("%s", st[k].name);
	printf("Manufacturer: ");
	scanf("%s", st[k].dev);
	printf("Diagonal: ");
	scanf("%s", st[k].diag);
	printf("Resolution: ");
	scanf("%s", st[k].razr);
	printf("Matrix: ");
	scanf("%s", st[k].matr);
	printf("Curved screen: ");
	scanf("%s", st[k].izog);
	printf("HDMI connector: ");
	scanf("%s", st[k].razh);
	return st[k];
}

int add_moni(moni_t* arr, int size, moni_t st) {
	
	//проверки памяти
	arr[size] = st;
	return size++;
}

void add(int* srt, int k)
{
	srt[k] = k;
	return srt;
}