/******************************************************************************
文 件 名    HW02_05
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    HW20_05
截止日期    2016年4月13日

简述：
 空格处理 多个空格替换为1个空格 
******************************************************************************/

#include<stdio.h>
#include<string.h>


int getline_(char s[], int lim);


int main()
{
	int N; 
	scanf("%d", &N);
	char c[20][100];
	for (int i = 1; i <= N; i++)
	{
		getline_(c[i],100);
		printf("%c", c[i][1]);
	}
}


int getline_(char s[], int lim)
{
	int c, i;
	i = 1;
	while ((c = getchar()) != EOF&&c != '\n'&& --lim>0)
	{
		s[i] = c;
	}
	if (c == '\n') 
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}









#include <stdio.h>
void main(void)
{
	int i, n, s = 1;
	printf("Please enter n:");
	scanf("%d", n);
	for (i = 1, i <= n, i++)
		s = s*i;
	printf("%d! = %d", n, s);
}
