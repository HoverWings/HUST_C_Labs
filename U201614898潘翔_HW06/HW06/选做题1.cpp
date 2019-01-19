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
******************************************************************************/

#include<stdio.h>
#include <string.h>
#include <math.h>
#define N 20
#define M 10

int an, bn, fa = 1, fb = 1;         /* 把an,bn,k设为全局变量,an纪录第一个高精度数组的位数,bn纪录第二个高精度数组的位数,k纪录输出结果的位数*/
char b1[250], b2[250];           /*记录需要计算的两个高精度数据  */

void Input(int a1[], int a2[]);
void addition(int a[], int b[], int q);

int main()
{
	int a[250] = { 0 }, b[250] = { 0 };
	Input(a, b);
	printf("\n%s+%s=", b1, b2); 
	addition(a, b, 0);
	return 0;
}


void Input(int a1[], int a2[])
{
	int i, ai = 1, bi = 1;
	scanf("%s%s", b1, b2);                      /*输入两个高精度数据 */
	for (i = 0; i<N; i++,ai++)
	{
			a1[i] = b1[an - ai] - '0';
	}     
	for (i = N; i<N+M; i++, ai++)
	{
		a1[i] = b1[an - ai] - '0';
	}   
	for (i = 0; i<N; i++, ai++)
	{
		a2[i] = b2[bn - bi] - '0';
	}
	for (i = N; i<N + M; i++, ai++)
	{
		a2[i] = b2[bn - bi] - '0';
	}
}

//
//void input(int a1[], int a2[])    /*函数input为输入函数,用来纪录两个待计算的高精度数据,以数组首地址为参数.以实现返回两个高精度数据*/
//{
//	int i, ai = 1, bi = 1;
//	int t1,t2;
//	scanf("%s%s", b1, b2);                      /*输入两个高精度数据 */
//	an = strlen(b1);                             /*an纪录b1的位数 */
//	an = 30;
//	bn = 30;
//	bn = strlen(b2);                            /*bn纪录b2的位数 */
//	if (b1[0] == 45) { an--; fa = -1; ai = 0; }           /*判断数组的符号 */
//	if (b2[0] == 45) { bn--; fb = -1; bi = 0; }
//	for (i = 0; i<an; ai++) 
//	{ 
//		if (b1[an - ai] == '.')
//		{
//			t1 = ai;
//		}
//		else
//		{
//			a1[i] = b1[an - ai] - '0';
//			i++;
//		}	
//		//printf("%d", a1[i]); 
//	}     /*把字符形数据b1转为整数形数据,同样用数组纪录 */
//	for (i = 0; i < bn; i++, bi++)
//	{
//		if (b2[bn - bi] == '.')
//		{
//			t2 = ai;
//		}
//		else
//		{
//			a2[i] = b2[bn - bi] - '0';    /* 同上  */
//			i++;
//		}
//		
//	}
//	return;
//}


void addition(int a[], int b[], int q)              /*高精度加法运算*/
{
	int i, c[251] = { 0 }, k;
	if (fa*fb>0 || q)//为两个正数相加
	{
		if (an > bn)
		{
			k = an;
		}
		else
		{
			k = bn;	/*用k纪录结果的最小位数*/
		}
		for (i = 0; i<k; i++)
		{
			c[i] = a[i] + b[i] + c[i];
			c[i + 1] = (int)c[i] / 10;
			c[i] = (int)c[i] % 10;
		}                                                 /*高精度加法运算过程*/
		if (c[k]) k++;                                     /*判断最后结果的位数*/
		if (fa<0 && q || fa<0) printf("-");
		for (i = k - 1; i >= 0; i--)
		{
			printf("%d", c[i]);         /*输出结果*/
		}
		return;
	}
	//else subtraction(a, b, 1);
	return;
}

