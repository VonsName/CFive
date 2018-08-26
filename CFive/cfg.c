#define _CRT_SECURE_NO_WARNINGS
#include "cfg.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 2048


/**
 * 写入配置文件
 */
int writeCfg(const char *fileName, const  char *key, const char *value)
{
	if (fileName==NULL||key==NULL||value==NULL)
	{
		printf("参数不能为空\n");
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
				printf("key重复覆盖\n");
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
	fseek(fp, 0, SEEK_END);//把文件指针移动到文件末尾

	int length = ftell(fp);//获取文件的长度

	  
	if (length>MAXSIZE)
	{
		printf("文件长度过长\n");
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
 * 读取配置文件
 */
int getCfg(const char *fileName, const char *key, char **value)
{
	if (fileName==NULL||key==NULL)
	{
		printf("参数不能为空\n");
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
		//判断是否存在=号
		p=strchr(buf, '=');
		if (p==NULL)
		{
			continue;
		}

		//判断是否存在key
		p = strstr(buf, key);
		if (p==NULL)
		{
			continue;
		}
		//移动p指针到key的末尾
		p = p + strlen(key);
		//判断key后面是否存在=号
		p = strchr(p, '=');
		if (p ==NULL)
		{
			return -2;
		}
		//指针p移动一个字节,到=号后面
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

