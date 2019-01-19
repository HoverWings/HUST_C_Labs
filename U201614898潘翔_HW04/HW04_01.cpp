/******************************************************************************
文 件 名    HW04_01
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    HW04_01
截止日期    2016年4月27日

简述：
三角形的面积是，其中，a,b,c为三角形的三边，定义两个带参数的宏，一个用来求s，另一个用来求area。编写程序，用带参数的宏来计算三角形的面积。
******************************************************************************/

#include<stdio.h>
#include<math.h>
#define s(a,b,c) (a+b+c)/2
#define area(a,b,c) sqrt(s*(s-a)*(s-b)*(s-c))
int main()
{
	double a, b, c;
	while (scanf("%lf%lf%lf", &a, &b, &c)!=EOF)
	{
		int s = s(a, b, c);
		double area = area(a, b, c);
		printf("%d ", s);
		printf("%lf\n", area);
	}
	return 0;
}