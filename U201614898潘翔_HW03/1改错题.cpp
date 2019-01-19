/******************************************************************************
文 件 名    1改错题 
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    1改错题 
截止日期    2016年4月20日

简述：
 源程序改错 
******************************************************************************/


#include "stdio.h"
long sum_fac(int n);
int main(void)
{
    int k;
    for(k=1;k<6;k++)
         printf("k=%d\tthe sum is %ld\n",k,sum_fac(k));
}
long sum_fac(int n)
{
    long s=0;
    int i;
    long fac;
    for(i=1;i<=n;i++)
    {
    	fac*=i;
        prinf("%d",fac);
        s+=fac;
	}
        
    
    return s;
}
