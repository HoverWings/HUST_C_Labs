/******************************************************************************
文 件 名    2替换题_02 
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    2替换题_02
截止日期    2016年4月20日

简述：
 源程序替换
******************************************************************************/



#include <stdio.h>
float sum_fac(int n);
void main(void)
{
	int k;
	for (k = 1; k<6; k++)
		printf("k=%d\tthe sum is %f\n", k, sum_fac(k));
}
float sum_fac(int n)
{
	float s = 0;
	int i;
	float fac = 1;
	for (i = 1; i <= n; i++)
	{
		fac *= (float)1 / i;
		//printf("%lf\n", fac);
		s += fac;
	}
	return s;
}
