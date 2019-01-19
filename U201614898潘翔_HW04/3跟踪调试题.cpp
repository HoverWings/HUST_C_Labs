/******************************************************************************
文 件 名    3跟踪调试题 
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    1改错题 
截止日期    2016年4月27日

简述：
 跟踪调试题 
******************************************************************************/

#include<stdio.h>
#include<assert.h>
#define R
int integer_fraction(float x);
int  main(void)
{
	float  r, s;
	int s_integer=0;
    printf("input a number: ");
    scanf("%f",&r);
    #ifdef  R
       s=3.14159*r*r;
       printf("area of round is: %f\n",s);
       s_integer=integer_fraction(s);
       printf("the integer fraction of area is %d\n", s_integer);
       assert((s-s_integer)<1.0);
    #endif
}

int integer_fraction(float x)
{
	int i = x;
	return i;
}

 

 
