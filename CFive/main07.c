#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 结构体一旦定义,结构体中的成员的内存布局就定下来了;
 */
typedef struct User
{
	char buf[64];
	int age;
	char *name;
}User;


/**
 * 浅拷贝 编译器的=号操作符和memcpy()只会把指针变量的值(内存空间的地址)拷贝
 *	但是不会拷贝指针变量指向的内存空间
 */
void copyUser(User *to, User *from)
{
	//*to = *from;
	//memcpy(to, from,sizeof(User));
}


void copyUser1(User *to, User *from)
{
	//深拷贝
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
		//free(u2.name); //段错误,因为上面copyUser()是浅拷贝,name指向的是同一段内存空间;
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
	//int offsize = (int)&(u->age);//64 ->age相对于User结构体的偏移量
	int offsize = (int)&(u->age) - (int)u;//64
	printf("%d\n", offsize);
	return 0;
}
