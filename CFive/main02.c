#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main021(int argc,char *argv[])
{

	//a��������Ԫ�ص�ַ,a+1�Ĳ�����4���ֽ�
	//&a����������ĵ�ַ &a+1�Ĳ�����3*4���ֽ�
	int a[] = { 1,2,3 };

	typedef int(MyArray)[5];//����һ��������������
	MyArray array;//����һ�������������͵ı���array,�൱��int array[5];

	
	for ( int i=0;i<5;i++)
	{
		array[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}


	printf("\n");
	MyArray *p = &array;//����ָ��,����һ���������͵�ָ�������ָ������ĵ�ַ

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
	typedef int(*PMyArray)[5];//����һ������ָ����������

	PMyArray parray;//����һ������ָ�����,����������һ��ָ�������С�ڴ�
	int a[5];
	parray = &a;
	for (int i=0;i<5;i++)
	{
		//(*parray)[i] = i + 3;//����Ҫע��[]�����ȼ���*��
		*(*parray + i) = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ", (*parray)[i]);//����Ҫע��[]�����ȼ���*��
		printf("%d ", *(*parray + i));
	}

	return 0;
}

int main023()
{

	int(*pMyArray)[5];//ֱ�Ӷ���һ��ָ�����������ָ�����,
	int a[5];
	pMyArray = &a;
	for (int i = 0; i < 5; i++)
	{
		//(*parray)[i] = i + 3;//����Ҫע��[]�����ȼ���*��
		*(*pMyArray + i) = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ", (*parray)[i]);//����Ҫע��[]�����ȼ���*��
		printf("%d ", *(*pMyArray + i));
	}
	return 0;
}
