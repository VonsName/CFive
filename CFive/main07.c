#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * �ṹ��һ������,�ṹ���еĳ�Ա���ڴ沼�־Ͷ�������;
 */
typedef struct User
{
	char buf[64];
	int age;
	char *name;
}User;


/**
 * ǳ���� ��������=�Ų�������memcpy()ֻ���ָ�������ֵ(�ڴ�ռ�ĵ�ַ)����
 *	���ǲ��´��ָ�����ָ����ڴ�ռ�
 */
void copyUser(User *to, User *from)
{
	//*to = *from;
	//memcpy(to, from,sizeof(User));
}


void copyUser1(User *to, User *from)
{
	//���
	/*to->name = (char *)malloc(strlen(from->name) + 1);
	strcpy(to->name, from->name);*/
	(*to).name = (char *)malloc(strlen((*from).name) + 1);
	strcpy((*to).name, (*from).name);
}

int main071(int argc,char *argv[])
{
	
	User u1;
	u1.age = 23;
	u1.name = (char *)malloc(strlen("lisi") + 1);
	strcpy(u1.name, "lisi");
	printf("%s\n", u1.name);
	User u2;
	//copyUser(&u2, &u1);

	copyUser1(&u2, &u1);
	printf("%s\n", u2.name);

	if (u1.name!=NULL)
	{
		free(u1.name);
		u1.name = NULL;
	}

	if (u2.name!=NULL)
	{
		//free(u2.name); //�δ���,��Ϊ����copyUser()��ǳ����,nameָ�����ͬһ���ڴ�ռ�;
		free(u2.name);
		u2.name = NULL;
	}

	return 0;
}

int main072()
{
	User u1;
	User *u=NULL;
	u = &u1;
	//int offsize = (int)&(u->age);//64 ->age�����User�ṹ���ƫ����
	int offsize = (int)&(u->age) - (int)u;//64
	printf("%d\n", offsize);
	return 0;
}
