/******************************************************************************
文 件 名    HW03_01
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    HW03_01
截止日期    2016年4月20日

简述：
 递归实现两个正整数的最大公约数
******************************************************************************/


#include<stdio.h>
int MaxComDivisor(int a, int b);

int main()
{
	int a;
	int b;
	scanf("%d", &a);
	while (a != 0)
	{
		scanf("%d", &b);
		printf("%d\n", MaxComDivisor(a, b));
		scanf("%d", &a);
	}
	return 0;
}


int MaxComDivisor(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return MaxComDivisor(b, a%b);
	}
}
