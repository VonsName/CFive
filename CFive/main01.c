#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main01(int argc,char *argv[])
{
	
	//���ҷ���,���ַ������״γ��ֵ�λ��
	char *p = "abd,aaa,ddd";
	char *str = NULL;
	str = strchr(p, ',');

	char buf[20];
	memset(buf, 0, sizeof(buf));
	strncpy(buf, p, str - p);
	printf("%s\n", buf);//abd

	printf("%s\n", str+1); //aaa,ddd
	p = str + 1;
	str = strchr(p,',');

	strncpy(buf, p, str-p);

	printf("%s\n", buf);//aaa
	printf("%s\n", str + 1);//ddd

	return 0;
}
