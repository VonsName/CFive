#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main041(int argc,char *argv[],char **env)
{
	for (int i=0;i<argc;i++)
	{
		printf("%s\n", argv[i]);
	}

	printf("\n");
	//env->操作系统的环境变量
	for (int j = 0;  env[j]!=NULL; j++)
	{
		printf("%s\n", env[j]);
	}


	//指针数组自我结束,在不知道数组的长度的时候,'\0'
	char *buf[] = {"aaa","bbb","ccc",'\0'};

	for (int i=0;buf[i]!=NULL;i++)
	{
		printf("%s ", buf[i]);
	}

	getchar();
	return 0;
}
