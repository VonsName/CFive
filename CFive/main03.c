#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main031 (int argc,char *argv[])
{
	//��ά��������ָ��һά�����ָ��,+1�Ĳ���Ϊ����һά����Ĵ�С,(ÿ����άԪ�ش�С���ܺ�)
	int a[3][5],i=0,j=0;
	int tmp = 1;
	for (i=0;i<3;i++)
	{
		for (j=0;j<5;j++)
		{
			a[i][j] = tmp++;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("a=%d %d\n", a, a + 1);//a��������׵�ַ,a+1�Ĳ���Ϊ20���ֽ�,����ά��С*4���ֽ�(һά���ܳ���)
	printf("&a%d %d\n", &a, &a + 1);//&a��������׵�ַ,&a+1�Ĳ���Ϊ60���ֽ�,����������Ĵ�С*4=15*4;
							//(*(a + 0))[1]
	printf("%d\n", *(*(a + 0)+1));//a+0�����ά�е�0�е�������ַ 2��ָ�� *(a+0)��һ��ָ��,��0����Ԫ�ص�ַ
	printf("%d\n", (*(a + 0))[1]);

	printf("%d\n", (*a)[10]);//֤����ά�������ڴ��������Դ洢��
	return 0;
}
