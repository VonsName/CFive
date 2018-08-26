#define _CRT_SECURE_NO_WARNINGS
#include "cfg.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 2048


/**
 * д�������ļ�
 */
int writeCfg(const char *fileName, const  char *key, const char *value)
{
	if (fileName==NULL||key==NULL||value==NULL)
	{
		printf("��������Ϊ��\n");
		return -1;
	}

	FILE  *fp = NULL;
	fp = fopen(fileName, "ab+");
	if (fp==NULL)
	{
		perror("fopen");
		return -1;
	}
	char buf[MAXSIZE] = { 0 };
	char *pkey = NULL;
	char *temp = NULL;
	while (!feof(fp))
	{
		pkey= fgets(buf, MAXSIZE, fp);
		if (pkey!=NULL)
		{
			pkey=strstr(buf, key);
			if (pkey!=NULL)
			{
				printf("key�ظ�����\n");
				char *flag = "\n";
				temp = strcat(buf, flag);
				temp = strcat(buf, key);
				if (temp == NULL)
				{
					return -1;
				}
				flag = "=";
				temp = strcat(buf, flag);
				if (temp == NULL)
				{
					return -1;
				}
				temp = strcat(buf, value);
				if (temp == NULL)
				{
					return -1;
				}
				fputs(buf, fp);
				if (fp != NULL)
				{
					fclose(fp);
					fp = NULL;
				}
				return 0;
			}
			else {
				continue;
			}
		}
		else {
			break;
		}
	}

	if (pkey!=NULL)
	{
		return 0;
	}
	memset(buf, 0, MAXSIZE);
	char *flag = "\n";
	temp=strcat(buf, flag);
	temp = strcat(buf, key);
	if (temp==NULL)
	{
		return -1;
	}
	flag = "=";
	temp=strcat(buf, flag);
	if (temp == NULL)
	{
		return -1;
	}
	temp=strcat(buf, value);
	if (temp == NULL)
	{
		return -1;
	}
	fseek(fp, 0, SEEK_END);//���ļ�ָ���ƶ����ļ�ĩβ

	int length = ftell(fp);//��ȡ�ļ��ĳ���

	  
	if (length>MAXSIZE)
	{
		printf("�ļ����ȹ���\n");
		return -1;
	}
	//fputs("\n", fp);
	fputs(buf, fp);

	if (fp!=NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return 0;
}


/**
 * ��ȡ�����ļ�
 */
int getCfg(const char *fileName, const char *key, char **value)
{
	if (fileName==NULL||key==NULL)
	{
		printf("��������Ϊ��\n");
		return -5;
	}

	char *temp = NULL;
	char *p = NULL;
	char *tmp = (char *)malloc(1024);
	memset(tmp, 0, 1024);
	*value = tmp;
	FILE *fp = NULL;
	fp = fopen(fileName, "rb");
	if (fp==NULL)
	{
		perror("fopen");
		return -1;
	}

	char buf[MAXSIZE] = { 0 };
	while (!feof(fp))
	{
		memset(buf, 0, MAXSIZE);
		temp=fgets(buf, MAXSIZE, fp);
		if (temp ==NULL)
		{
			return -1;
		}
		//�ж��Ƿ����=��
		p=strchr(buf, '=');
		if (p==NULL)
		{
			continue;
		}

		//�ж��Ƿ����key
		p = strstr(buf, key);
		if (p==NULL)
		{
			continue;
		}
		//�ƶ�pָ�뵽key��ĩβ
		p = p + strlen(key);
		//�ж�key�����Ƿ����=��
		p = strchr(p, '=');
		if (p ==NULL)
		{
			return -2;
		}
		//ָ��p�ƶ�һ���ֽ�,��=�ź���
		p = p + 1;
		printf("%s\n", p);
		memcpy(*value, p, strlen(p));
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
	return 0;
}

