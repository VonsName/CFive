#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"
#define FILENAME  "C:/Users/vons0/Desktop/a.ini"
/**
* ����д�����ļ�
*/
void testwriteCfg()
{
	char key[125] = {0};
	char value[125] = {0};
	printf("������key:\t");
	scanf("%s", key);
	printf("�������keyΪ:%s\n", key);
	printf("������value:\t");
	scanf("%s", value);
	printf("�������valueΪ:%s\n", value);

	 int ret=writeCfg(FILENAME, key, value);
	 if (ret!=0)
	 {
		 printf("�����ļ�д��ʧ��\n");
		 return;
	 }
	 else {
		 printf("�����ļ�д��ɹ�\n");
	 }
}


/**
* ���Զ������ļ�
*/
void testgetCfg()
{
	char key[125] = { 0 };
	printf("������key:\n");
	scanf("%s", key);
	char *tmp = NULL;
	getCfg(FILENAME, key, &tmp);
	if (tmp!=NULL)
	{
		printf("%s\n", tmp);
		free(tmp);
		tmp = NULL;
	}
}

void showMenu()
{
	printf("\t\t\t************************************\n");
	printf("\t\t\t\t��������Ҫ���Ĳ���\n");
	printf("\t\t\t\t1.���������ļ���ȡ\n");
	printf("\t\t\t\t2.���������ļ�д��\n");
	printf("\t\t\t\t0.�˳�\n");
	printf("\t\t\t************************************\n");
}

int main(int argc,char *argv[])
{
	int choice=0;
	for (;;)
	{
		showMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			testwriteCfg();
			break;
		case 2:
			testgetCfg();
			break;
		case 0:
			exit(0);
			break;

		default:
			exit(0);
			break;
		}
	}
	return 0;
}
