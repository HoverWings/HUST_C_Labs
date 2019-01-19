/******************************************************************************
文 件 名    HW03_02
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    HW03_02
截止日期    2016年4月20日

简述：
	哥德巴赫猜想
******************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

void Goldbach(int k);
bool IsPrime(int k);
bool IsEven(int i);

int main()
{
	int begin, end;
	scanf("%d", &begin);
	while (begin!=0)
	{
		scanf("%d", &end);
		for (int i = begin; i<= end; i++)
		{
			if (IsEven(i))
			{
				Goldbach(i);
			}
		}
		printf("\n");
		scanf("%d", &begin);
	}
	return 0;
}


void Goldbach(int k)
{
	for (int i = 2; i <= k / 2; i++)
	{
		if (IsPrime(i) && IsPrime(k - i))
		{
			printf("%d=%d+%d\n", k, i, k - i);
			break;
		}
	}
}

bool IsPrime(int k)
{
	int m = (int)sqrt(k);
	for (int j = 2; j <= m; j++)
	{
		if (k%j == 0)
		{
			return false;
		}
	}
	return true;
}

bool IsEven(int i)
{
	if (i % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

