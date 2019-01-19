/******************************************************************************
文 件 名    2替换题
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    1改错题
截止日期    2016年4月27日

简述：
源程序修改替换题
******************************************************************************/
#include<stdio.h>
#define MAX(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))
float sum(float x, float y);
float f;
void main(void)
{
	int a, b, c;
	float d, e;
	int m;
	printf("Enter three integers:");
	scanf("%d%d%d", &a, &b, &c);
	printf("\nthe maximum of them is %d\n", MAX(a, b, c));
	printf("Enter two floating point numbers:");
	scanf("%f%f", &d, &e);
	printf("\nthe sum of them is  %f\n", sum(d, e));
}


float sum(float x, float y)
{
	return x+y;
}
