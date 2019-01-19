/******************************************************************************
文 件 名	选做题1
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    HW06_01
截止日期    2016年5月18日
简述：
设有N位整数和M位小数（N=20，M=10）的数据a,b。编程计算a+b并输出结果。
如：12345678912345678912.1234567891 + 98765432109876543210.0123456789
12345678912345678912.1234567891
98765432109876543210.0123456789
******************************************************************************/

#include<stdio.h>
#include<string.h>
char s1[110], s2[110];//存放字符串形式
int num1[220], num2[220];//存放数字形式
char result[220];

void init();
void CharToNum(char *s, int *a);
void sum(char *result, int* num1, int* num2);
void print();

int main()
{
	while (scanf("%s %s", s1, s2) != EOF)
	{
		init(); 								//每计算一次初始化数组  
		CharToNum(s1, num1);
		CharToNum(s2, num2);
		sum(result, num1,num2);					//进位求和过程   
		print();
	}
	return 0;
}


void init()//对数组初始化处理
{
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(result, 0, sizeof(result));
}

void CharToNum(char *s, int *a)
{
	int len = strlen(s);
	int k;
	if (strchr(s, '.') != NULL)							//判断有无小数点   
		k = strchr(s, '.') - s;							//标记小数点的位置   
	else
		k = len;										//无小数点   
	for (int i = k + 1, j = 99; i<len; i++, j--)		//小数点后面的存到前 
		a[j] = s[i] - '0';
	for (int i = k - 1, j = 100; i >= 0; i--, j++)		//小数点前面的存放到后 
		a[j] = s[i] - '0';
}

void sum(char *result, int* num1,int* num2)
{
	int s, v = 0;
	for (int i = 0; i<220; i++)
	{
		s = num1[i] + num2[i] + v;
		result[i] = s % 10;
		v = s / 10;
	}
}

void print()
{
	int i = 220;
	while (result[i] == 0 && i >= 100)
	{
		i--;
	}
	int j = 0;
	while (result[j] == 0 && j<100)
	{
		j++;
	}
	if (i == 99 && j == 100)							//全是零的情况  
		printf("0\n");
	else
	{
		for (; i >= 100; i--)
		{
			printf("%d", result[i]);
		}
		if (j != 100)
		{
			printf(".");
		}
		for (int i = 99; i >= j; i--)
			printf("%d", result[i]);
		printf("\n");
	}
}










