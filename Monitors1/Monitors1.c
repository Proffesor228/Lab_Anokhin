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
	char name[8][20] = { "��������: ","�������������: ","���������: ","����������: ","�������: ","��������� �����: ","������ HDMI: " };
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
		printf("�������� ������ ��������:\n1)������� ����� ������\n2)����� ������\n3)������� ���� ������\n4)����������� �� �������������\n5)�������� ������\n6)�������� ��������� �������\n7)��������� ������\n");
		scanf("%d", &num);
		if (num > 7 || num < 1) printf("\n������ �������� �� ����������\n");
		switch (num)
		{
		case 1:
			printf("������� ��������:");
			scanf("%s", st[i].name);
			printf("�������������: ");
			scanf("%s", st[i].dev);
			sort[i] = i;
			printf("���������: ");
			scanf("%s", st[i].diag);
			printf("����������: ");
			scanf("%s", st[i].razr);
			printf("�������: ");
			scanf("%s", st[i].matr);
			printf("��������� �����: ");
			scanf("%s", st[i].izog);
			printf("������ HDMI: ");
			scanf("%s", st[i].razh);
			i++;
			break;
		case 2:
			printf("���� ��� ������:\n1) �������\n2) ��������� � �� ��� ������\n3) �� ������� � ���������");
			scanf("%d", &num);
			switch (num)
			{
			case 1:
				printf("������� ����: ");
				scanf("%s", kl);
				for (int j = 0;j < i;j++)
				{
					if (strstr(st[j].matr, kl) != NULL) printf("\n%s%30s %s%10s %s%8s %s%10s %s%5s %s%3s %s%4s", name[0], st[j].name, name[1], st[j].dev, name[2], st[j].diag, name[3], st[j].razr, name[4], st[j].matr, name[5], st[j].izog, name[6], st[j].razh);
				}
				break;
			case 2:
				printf("������� ����:\n1)� ��\n2)� ������\n");
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
					printf("\n������� �� �������");
					break;
				}
				break;
			case 3:
				printf("������� ���� ��� �������: \n");
				scanf("%s", kl);
				printf("������� ���� ��� ���������:\n1)� ��\n2)� ������\n");
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
					printf("\n������� �� �������");
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
			printf("������� ����� ������:");
			scanf("%d", &num1);
			printf("������� ��������:");
			scanf("%s", st[num1-1].name);
			printf("�������������: ");
			scanf("%s", st[num1-1].dev);
			printf("���������: ");
			scanf("%s", st[num1-1].diag);
			printf("����������: ");
			scanf("%s", st[num1-1].razr);
			printf("�������: ");
			scanf("%s", st[num1-1].matr);
			printf("��������� �����: ");
			scanf("%s", st[num1-1].izog);
			printf("������ HDMI: ");
			scanf("%s", st[num1-1].razh);
			break;
		case 6:
			printf("������� ������� ��������?\n");
			scanf("%d", &num1);
			for (int j = 0;j < num1;j++)
			{
				printf("������� ��������:");
				scanf("%s", st[i].name);
				printf("�������������: ");
				scanf("%s", st[i].dev);
				sort[i] = i;
				printf("���������: ");
				scanf("%s", st[i].diag);
				printf("����������: ");
				scanf("%s", st[i].razr);
				printf("�������: ");
				scanf("%s", st[i].matr);
				printf("��������� �����: ");
				scanf("%s", st[i].izog);
				printf("������ HDMI: ");
				scanf("%s", st[i].razh);
				i++;
			}
			break;
		case 7:
			fl = fopen("monitors.bin", "wb+");
			fwrite(&st, sizeof(st), 1, fl);
			fwrite(&i, sizeof(i), 1, fl);
			fwrite(&sort, sizeof(sort), 1, fl);
			printf("\n������ ���������\n");
			break;
		}
		getchar();
		printf("\n����������? (y-��,n-���)\n");
		scanf("%c", &ans);
	}
}