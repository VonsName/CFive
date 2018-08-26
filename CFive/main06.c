#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _sort(char **p1, int num1, char(*p2)[30], int num2, char ***p3, int* num3)
{
	if (p3==NULL||p1==NULL||p2==NULL)
	{
		return -1;
	}
	int i = 0;
	//分配二级指针的内存
	*p3 = (char **)malloc(sizeof(char *)*(num1 + num2));
	memset(*p3, 0, sizeof(*p3));
	//char **p3tmp = *p3;
	if (*p3==NULL)
	{
		return -2;
	}

	char **p1tmp = p1;
	for (i=0;i<num1;i++)
	{
		int tmplen = strlen(p1tmp[i]) + 1;
		(*p3)[i] = (char *)malloc(sizeof(char)*tmplen);
		if ((*p3)[i]==NULL)
		{
			return -3;
		}
		memset((*p3)[i], 0, sizeof((*p3)[i]));
		strcpy((*p3)[i], p1tmp[i]);
	}
	
	for (int j=0;j<num2;j++)
	{
		int tmplen = strlen(p2[j]) + 1;
		(*p3)[i] = (char *)malloc(sizeof(char)*tmplen);
		if ((*p3)[i]==NULL)
		{
			return -5;
		}
		memset((*p3)[i], 0, sizeof((*p3)[i]));
		strcpy((*p3)[i], p2[j]);
		i++;
	}

	*num3 = num1 + num2;

	char **p3tmp = *p3;
	char *ctmp = NULL;
	char buf[100];
	for ( int k=0;k<*num3;k++)
	{
		for (int m=k;m<*num3;m++)
		{
			if (strcmp(p3tmp[k],p3tmp[m])<0)
			{
				ctmp = p3tmp[k];
				p3tmp[k] = p3tmp[m];
				p3tmp[m] = ctmp;
			/*	strcpy(buf, p3tmp[k]);
				strcpy(p3tmp[k], p3tmp[m]);
				strcpy(p3tmp[m], buf);*/
			}
		}
	}
	return 0;
}


void _print(char ***p3, int num)
{
	if (p3==NULL)
	{
		return;
	}
	if (*p3==NULL)
	{
		return;
	}
	char **tmp = *p3;
	for ( int i=0;i<num;i++)
	{
		printf("%s\n", tmp[i]);
	}
}

void free_sort(char ***p,int num)
{
	if (p==NULL)
	{
		return;
	}
	if (*p!=NULL)
	{
		for (int i=0;i<num;i++)
		{
			if ((*p)[i]!=NULL)
			{
				free((*p)[i]);
			}
		}
		free(*p);
		*p = NULL;
	}
}


/**
 * C提高第五天第七课时
 */
int main061(int argc,char *argv[])
{
	
	char *p1[] = {
		{"aaaaa"},
		{ "bbbbb" },
		{ "cccccc" },
	};

	char buf[10][30] = {
		{"111111"},
		{ "22222" },
		{ "33333" },
	};

	char **p3 = NULL;
	int num = 0;
	int len1 = sizeof(p1) / sizeof(*p1);
	int len2 = 3;
	int ret=_sort(p1, len1, buf, len2, &p3, &num);
	if (ret!=0)
	{
		printf("_sort error\n");
		return ret;
	}

	_print(&p3, num);

	free_sort(&p3, num);

	return ret;
}
