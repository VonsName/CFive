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
	//env->����ϵͳ�Ļ�������
	for (int j = 0;  env[j]!=NULL; j++)
	{
		printf("%s\n", env[j]);
	}


	//ָ���������ҽ���,�ڲ�֪������ĳ��ȵ�ʱ��,'\0'
	char *buf[] = {"aaa","bbb","ccc",'\0'};

	for (int i=0;buf[i]!=NULL;i++)
	{
		printf("%s ", buf[i]);
	}

	getchar();
	return 0;
}
