#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char **sName;
}Teacher;


Teacher * createTeacher(Teacher **pt, int num)
{
	//char *p = (char *)malloc(sizeof(char) * num);
	Teacher *tmp = (Teacher *)malloc(sizeof(Teacher)*num);//Teacher tArray[3];
	

	for (int i=0;i<num;i++)
	{
		char **stmp = NULL;
		stmp = (char **)malloc(sizeof(char *)*num);
		for (int j = 0; j < num; j++)
		{
			stmp[j] = (char *)malloc(sizeof(char)*60);
			memset(stmp[j], 0, sizeof(stmp[j]));
		}
		tmp[i].sName = stmp;
	}
	*pt = tmp;
	return *pt;
}


void freeTea(Teacher **t)
{
	if (t==NULL)
	{
		return;
	}

	for (int j=0;j<3;j++)
	{
		char **tmp = (*t+j)->sName;
		if (tmp != NULL)
		{
			for (int i = 0; i < 3; i++)
			{
				if (tmp[i] != NULL)
				{
					free(tmp[i]);
					tmp[i] = NULL;
				}
			}
			free(tmp);
		}
	}

	if (*t!=NULL)
	{
		free(*t);
		*t = NULL;
	}
}

int main051(int argc,char *argv[])
{
	
	Teacher t1 = { "lisi",23 };
	printf("%s\n", t1.name);//������.��Ѱַ����,����name��t1�����е�ƫ����(��cpu��),û�в����ڴ�
											//������->Ҳ��Ѱַ����,��cpu�м���,�������ڴ�
	printf("%d\n", t1.age);

	Teacher *pt = NULL;
	createTeacher(&pt,3);
	for (int i=0;i<3;i++)
	{
		(pt + i)->age = 23+i+1;
	}

	for (int i=0;i<3;i++)
	{
		printf("%d ", (*(pt + i)).age);
	}
	freeTea(&pt);
	return 0;
}


/**
 * �ṹ����2��ָ��
 */
int main052()
{

	Teacher *pt = NULL;
	createTeacher(&pt, 3);
	for (int i = 0; i < 3; i++)
	{
		(pt + i)->age = 23 + i + 1;
		char **tmp= (pt + i)->sName;
		for (int j=0;j<3;j++)
		{
			strcpy(tmp[j], "����");
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", (*(pt + i)).age);
		char **tmp = (pt + i)->sName;
		for (int j = 0; j < 3; j++)
		{
			//printf("%s  ", *((pt + i)->sName));
			printf("%s ", tmp[j]);
		}
		printf("\n");
	}
	freeTea(&pt);
	return 0;
}
