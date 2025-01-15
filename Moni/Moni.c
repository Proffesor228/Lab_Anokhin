#include <stdio.h>
#include <string.h>
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
moni_t input_moni(moni_t* st, int k);
int sorti(int* sort1,int* sort, moni_t* st, int i);
moni_t edit_moni(moni_t* st);
void savetxt(FILE* txt, moni_t st[], char* name, int i);
void savefl(FILE* fl, moni_t* st, int* sort, int i);
void search(moni_t* st, int i, char* name, size_t n);
void search(moni_t* st, char name[8][20], int i);
void main()
{
	FILE* fl;
	FILE* txt;
	fl = fopen("monitors.bin", "ab+");
	txt = fopen("monitors.txt", "w");
	if (fl == NULL || txt == NULL) {
		perror("Error occured while opening file");
		return 1;
	}
	char ans = 'y';
	char kl[40];
	char name[8][20] = { "Name: ","Manufacturer: ","Diagonal: ","Resolution: ","Matrix: ","Curved screen: ","HDMI connector: " };
	int num, i = 0, num1;
	int sort[50], sort1[50];
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
		printf("Select the desired action:\n1)Create a new record\n2)Search for a record\n3)Display database\n4)Sort by manufacturer\n5)Edit record\n6)Delete record\n7)Add multiple records\n8)Save data");
		scanf("%d", &num);
		if (num > 8 || num < 1) printf("\nThe required action was not found.\n");
		switch (num)
		{
		case 1:
			input_moni(st, i);
			sort[i] = i;
			i++;
			break;
		case 2:
			search(st, name, i);
			break;
		case 3:
			for (int j = 0;j < i;j++)
			{
				printf("\n%d) %s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s",j+1, name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
			}
			break;
		case 4:
			sorti(sort1,sort, st, i);
			for (int m = 0; m < i; m++)
			{
				printf("\n%d) %s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s",m+1, name[0], st[sort1[m]].name, name[1], st[sort1[m]].dev, name[2], st[sort1[m]].diag, name[3], st[sort1[m]].razr, name[4], st[sort1[m]].matr, name[5], st[sort1[m]].izog, name[6], st[sort1[m]].razh);
			}
			break;
		case 5:
			for (int j = 0;j < i;j++)
			{
				printf("\n%d) %s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", j + 1, name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
			}
			edit_moni(st);
			break;
		case 7:
			printf("How many records add?\n");
			scanf("%d", &num1);
			for (int j = 0;j < num1;j++)
			{
				input_moni(st, i);
				i++;
				sort[i] = i;
			}
			break;
		case 8:
			fl = fopen("monitors.bin", "wb+");
			txt = fopen("monitors.txt", "w");
			fwrite(&st, sizeof(st), 1, fl);
			fwrite(&i, sizeof(i), 1, fl);
			fwrite(&sort, sizeof(sort), 1, fl);
			for (int j = 0;j < i;j++)
			{
				fprintf(txt, "%d) %s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s\n", j+1, name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
			}
			printf("\nData saved succesfully\n");
			break;
		case 6:
			for (int j = 0;j < i;j++)
			{
				printf("\n%d) %s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", j + 1, name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
			}
			printf("Choose the record to delete\n");
			scanf("%d", &num1);
			for (int z = num1-1;z < i;z++) st[z] = st[z+1];
			i -= 1;
			break;
		}
		getchar();
		printf("\nContinue? (y-yes,n-no)\n");
		scanf("%c", &ans);
	}
}

moni_t input_moni(moni_t* st, int k) 
{
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
int sorti(int sort1[50], int sort[50], moni_t* st, int i)
{
	int frst = 0;
	char pz[15];
	char dev[50][20];
	for (int z = 0;z < i;z++)
	{
		sort1[z] = sort[z];
	}
	for (int z = 0;z < i;z++)
	{
		strcpy(dev[z], st[z].dev);
	}
	for (int j = 0;j < i;j++)
	{
		int result = strcmp(dev[j], dev[j + 1]);
		if (result > 0) {
			frst = sort1[j];
			sort1[j] = sort1[j + 1];
			sort1[j + 1] = frst;
			strcpy(pz, dev[j]);
			strcpy(dev[j], dev[j + 1]);
			strcpy(dev[j + 1], pz);
			j = -1;
		}
	}
	return sort1;
}
moni_t edit_moni(moni_t* st)
{
	int num1;
	printf("Enter the entry number: ");
	scanf("%d", &num1);
	printf("Enter the name: ");
	scanf("%s", st[num1 - 1].name);
	printf("Manufacturer: ");
	scanf("%s", st[num1 - 1].dev);
	printf("Diagonal: ");
	scanf("%s", st[num1 - 1].diag);
	printf("Permission: ");
	scanf("%s", st[num1 - 1].razr);
	printf("Matrix: ");
	scanf("%s", st[num1 - 1].matr);
	printf("Curved screen: ");
	scanf("%s", st[num1 - 1].izog);
	printf("HDMI connector: ");
	scanf("%s", st[num1 - 1].razh);
	return st[num1-1];
}
void savetxt(FILE*txt,moni_t st[], char* name, int i)
{
	for (int j = 0;j < i;j++)
	{
		fprintf(txt, "%d) %s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s\n", j, name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
	}
	printf("\nData saved succesfully\n");
}
void savefl(FILE*fl,moni_t*st,int*sort,int i)
{
	fl = fopen("monitors.bin", "wb+");
	fwrite(&st, sizeof(st), 1, fl);
	fwrite(&i, sizeof(i), 1, fl);
	fwrite(&sort, sizeof(sort), 1, fl);
	printf("\nData saved succesfully\n");
}
void search(moni_t* st, char name[8][20], int i)
{
	int num = 0;
	char kl[30];
	int num1 = 0;
	printf("Search field:\n1) Matrix\n2) Diagonal in cm or inches\n3) By matrix and diagonal");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("Enter the key:");
		scanf("%s", kl);
		for (int j = 0; j < i; j++)
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
			for (int j = 0; j < i; j++)
			{
				if (strstr(st[j].diag, "cm") != NULL) printf("\n%s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
			}
			break;
		case 2:
			for (int j = 0; j < i; j++)
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
			for (int j = 0; j < i; j++)
			{
				if (strstr(st[j].diag, "sm") != NULL) if (strstr(st[j].matr, kl) != NULL) printf("\n%d) %s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", j + 1, name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
			}
			break;
		case 2:
			for (int j = 0; j < i; j++)
			{
				if (strstr(st[j].diag, "\"") != NULL) if (strstr(st[j].matr, kl) != NULL) printf("\n%d) %s%30s | %s%10s | %s%8s | %s%10s | %s%5s | %s%3s | %s%4s", j + 1, name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
			}
			break;
		default:
			printf("\nNo records found");
			break;
		}
	}
}