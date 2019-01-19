#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	char ch;
	FILE *fp;
	if (argc != 2)								//命令行输入参数的个数
	{
		printf("Argument error!\n");
		exit(-1);
	}
	//if ((fp = fopen(argv[1], "r")) == NULL) 
	if ((fp= freopen(argv[1], "r", stdin)) == NULL)
	{        /*fp指向filename*/
		printf("Can't open %s file!\n", argv[1]);	/*
													argv[0] 指向程序运行的全路径名
													argv[1] 指向在DOS命令行中执行程序名后的第一个字符串
													argv[2] 指向执行程序名后的第二个字符串
													...
													argv[argc]为NULL。*/
		exit(-1);
	}
	while ((ch = fgetc(fp))!= EOF)           /*从filename中读字符*/
		putchar(ch);					   /*向显示器中写字符*/
	fclose(fp);							 /*关闭filename*/
	return 0;
}
