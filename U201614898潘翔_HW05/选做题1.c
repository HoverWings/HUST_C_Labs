/******************************************************************************
文 件 名    选做题1 
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    选做题1 
截止日期    2016年5月4日

简述：
在字符串插入函数 strnins(char s[], char t[], int n);

******************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool strnins(char s[], char t[], int n);

int main()
{
	char a[50] = "The adopted symbol is ", b[27] = "abcdefghijklmnopqrstuvwxyz";
	strnins(a, b, 5);
	printf("%s\n", a);
	return 0;
}


bool strnins(char s[], char t[], int n)
{
	char temp[100];
	if (n < 0 || n>strlen(s))
	{
		printf("Error!\n");
		return false;
	}
	strcpy(temp, s + n);
	strcpy(s+n, t);//t+n之后添加到s结尾处
	strcat(s, temp);

	return true;
}


