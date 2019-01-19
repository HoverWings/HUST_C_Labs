/******************************************************************************
文 件 名    1改错题 
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    1改错题 
截止日期    2016年4月27日

简述：
 源程序改错 
******************************************************************************/


#include <stdio.h> 
#define SUM a+b
#define DIF a-b
#define SWAP(a,b)  t=a;a=b;b=t
void main()
{
	int a;
	int b, t;
    printf("Input two integers a, b:");
    scanf("%d%d", &a,&b);
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d", SUM, (SUM)*(DIF));
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);
}

