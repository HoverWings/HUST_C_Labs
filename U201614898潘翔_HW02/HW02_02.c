/******************************************************************************
文 件 名    HW02_02
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    HW20_02
截止日期    2016年4月13日

简述：
 杨辉三角 
******************************************************************************/

#include<stdio.h>

void YangHui(int n);
void CalculateYH(int n);
void PrintSpace(int n);
int DigitNum(int n);
int a[13][13];

int main()
{
	
	int n ;
	scanf("%d", &n);
	while (n != 0) 
	{
		YangHui(n);
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}

void CalculateYH(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		a[i][1] = 1;      /*第一列全置为一*/
	}
	for (i = 2; i <=n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
}

void YangHui(int n)
{
	CalculateYH(n);
	int i, j;
	
	for (i = 1; i<=n; i++)   /*输出杨辉三角*/
	{
		PrintSpace(2 * (n - i));
		for (j = 1; j <= i; j++)
		{
			if ((j == i))
			{
				printf("%d", a[i][j]);
			}
			else
			{
				printf("%d", a[i][j]);
				PrintSpace(4 - DigitNum(a[i][j + 1]));
			}
		}
		printf("\n");
	}
}

void PrintSpace(int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf(" ");
	}
}

int DigitNum(int n)
{
	int sum=0;
	while (n) 
	{
		sum++;
		n /= 10;
	}
	return sum;
}


