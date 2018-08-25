#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main031 (int argc,char *argv[])
{
	//多维数组名是指向一维数组的指针,+1的步长为整个一维数组的大小,(每个二维元素大小的总和)
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

	printf("a=%d %d\n", a, a + 1);//a是数组的首地址,a+1的步长为20个字节,即二维大小*4个字节(一维的总长度)
	printf("&a%d %d\n", &a, &a + 1);//&a是数组的首地址,&a+1的步长为60个字节,是整个数组的大小*4=15*4;
							//(*(a + 0))[1]
	printf("%d\n", *(*(a + 0)+1));//a+0代表二维中第0行的整个地址 2级指针 *(a+0)是一级指针,第0行首元素地址
	printf("%d\n", (*(a + 0))[1]);

	printf("%d\n", (*a)[10]);//证明多维数组在内存中是线性存储的
	return 0;
}
