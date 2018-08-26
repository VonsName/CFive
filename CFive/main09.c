#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"
#define FILENAME  "C:/Users/vons0/Desktop/a.ini"
/**
* 测试写配置文件
*/
void testwriteCfg()
{
	char key[125] = {0};
	char value[125] = {0};
	printf("请输入key:\t");
	scanf("%s", key);
	printf("您输入的key为:%s\n", key);
	printf("请输入value:\t");
	scanf("%s", value);
	printf("您输入的value为:%s\n", value);

	 int ret=writeCfg(FILENAME, key, value);
	 if (ret!=0)
	 {
		 printf("配置文件写入失败\n");
		 return;
	 }
	 else {
		 printf("配置文件写入成功\n");
	 }
}


/**
* 测试读配置文件
*/
void testgetCfg()
{
	char key[125] = { 0 };
	printf("请输入key:\n");
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
	printf("\t\t\t\t请输入你要做的操作\n");
	printf("\t\t\t\t1.测试配置文件读取\n");
	printf("\t\t\t\t2.测试配置文件写入\n");
	printf("\t\t\t\t0.退出\n");
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
