#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main021(int argc,char *argv[])
{

	//a是数组首元素地址,a+1的步长是4个字节
	//&a是整个数组的地址 &a+1的步长是3*4个字节
	int a[] = { 1,2,3 };

	typedef int(MyArray)[5];//定义一个数组数据类型
	MyArray array;//声明一个数组数据类型的变量array,相当于int array[5];

	
	for ( int i=0;i<5;i++)
	{
		array[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}


	printf("\n");
	MyArray *p = &array;//数组指针,定义一个数组类型的指针变量并指向数组的地址

	for (int i=0;i<5; i++)
	{
		//(*p)[i] = i + 3;
		*(*p + i) = i + 3;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}

int main022()
{
	typedef int(*PMyArray)[5];//定义一个数组指针数据类型

	PMyArray parray;//声明一个数组指针变量,编译器分配一个指针变量大小内存
	int a[5];
	parray = &a;
	for (int i=0;i<5;i++)
	{
		//(*parray)[i] = i + 3;//这里要注意[]的优先级比*高
		*(*parray + i) = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ", (*parray)[i]);//这里要注意[]的优先级比*高
		printf("%d ", *(*parray + i));
	}

	return 0;
}

int main023()
{

	int(*pMyArray)[5];//直接定义一个指向数组的数组指针变量,
	int a[5];
	pMyArray = &a;
	for (int i = 0; i < 5; i++)
	{
		//(*parray)[i] = i + 3;//这里要注意[]的优先级比*高
		*(*pMyArray + i) = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ", (*parray)[i]);//这里要注意[]的优先级比*高
		printf("%d ", *(*pMyArray + i));
	}
	return 0;
}
