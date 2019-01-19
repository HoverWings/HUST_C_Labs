/******************************************************************************
文 件 名    HW02_03
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    HW20_03
截止日期    2016年4月13日

简述：
 整数翻转
******************************************************************************/


#include<stdio.h>
void NumReverse(int n);

int main()
{
	int n;
	scanf("%d", &n);
	while (n != 0) 
	{
		
		NumReverse(n);
		scanf("%d", &n);
	}
	return 0;

}

void NumReverse(int n)
{
	int ModNum = 0;// 余数  
	int result = 0;
	while (n / 10 != 0) //一位数跳出循环
	{

		ModNum = n % 10;
		n = n / 10;
		result = result * 10 + ModNum;
	}
	result=result * 10 + n;
	printf("%d\n", result);
}
