#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * fputc()
 */
int main081(int argc,char *argv[])
{
	FILE *fp = NULL;
	char *pname = "C:/Users/vons0/Desktop/a.txt";
	fp = fopen(pname, "w+");
	if (fp==NULL)
	{
		perror("fopne");
		return -1;
	}

	char a[] = { "abcdefg" };
	for (int i=0;i<strlen(a);i++)
	{
		fputc(a[i], fp);
	}
	fclose(fp);
	printf("hello world\n");
	return 0;
}


/**
 * fgetc()
 */
int main082()
{
	FILE *fp = NULL;
	char *pname = "C:/Users/vons0/Desktop/a.txt";
	fp = fopen(pname, "r+");
	if (fp == NULL)
	{
		perror("fopne");
		return -1;
	}

	while (!feof(fp))
	{
		char c = fgetc(fp);
		printf("%c ", c);
	}

	fclose(fp);
	return 0;
}

/**
 * fputs();
 */
int main083()
{
	FILE *fp = NULL;
	char *pname = "C:/Users/vons0/Desktop/a.txt";
	fp = fopen(pname, "w+");
	if (fp == NULL)
	{
		perror("fopne");
		return -1;
	}

	char a[] = { "abcdefg" };

	fputs(a, fp);
	fclose(fp);

	return 0;
}


/**
 * fgets();
 */
int main04()
{

	FILE *fp = NULL;
	char *pname = "C:/Users/vons0/Desktop/a.txt";
	fp = fopen(pname, "r+");
	if (fp == NULL)
	{
		perror("fopne");
		return -1;
	}

	char buf[50];
	memset(buf, 0, sizeof(buf));
	while (!feof(fp))
	{
		fgets(buf, sizeof(buf), fp);
	}
	printf("%s\n", buf);
	if (fp!=NULL)
	{
		goto End;
	}
End:
	fclose(fp);
	return 0;
}


/**
 * fwrite()
 */
int main085()
{

	FILE *fp = NULL;
	char *pname = "C:/Users/vons0/Desktop/a.txt";
	fp = fopen(pname, "w+");
	if (fp == NULL)
	{
		perror("fopne");
		return -1;
	}
	char buf[] = { "12121abdas" };

	fwrite(buf, 1, sizeof(buf), fp);

	if (fp != NULL)
	{
		goto End;
	}
End:
	fclose(fp);
	
	return 0;
}


/**
 * fread()
 */
int main086()
{
	FILE *fp = NULL;
	char *pname = "C:/Users/vons0/Desktop/a.txt";
	fp = fopen(pname, "rb+");
	if (fp == NULL)
	{
		perror("fopne");
		return -1;
	}

	char buf[50];
	while (!feof(fp))
	{
		fread(buf, 1, sizeof(buf), fp);
		printf("%s\n", buf);
	}

	if (fp != NULL)
	{
		goto End;
	}
End:
	fclose(fp);
	return 0;
}