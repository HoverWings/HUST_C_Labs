/******************************************************************************
文 件 名    HW01_01
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    HW20_01
截止日期    2016年4月13日

简述：
 牛顿法求方程的近似根
******************************************************************************/


#include<stdio.h>
#include<math.h>
int a, b, c, d;
float Solve(float a, float b, float c, float d);

int main()
{
	a = 3; b = -4; c = -5; d = 13;
	printf("%lf\n", Solve(a, b, c, d));
	return 0;
}

float Solve(float a, float b, float c, float d)
{
	float x = 1, x0=2, f, f1;
	while (fabs(x - x0) >= 1e-5)
	{
		x0 = x;
		f = ((a*x0 + b)*x0 + c)*x0+d;
		f1 = (3 * a*x0 + 2 * b)*x0 + c;
		x = x0 - f / f1;
	}
	return x;
}
