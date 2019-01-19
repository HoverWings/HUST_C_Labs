/******************************************************************************
文 件 名    HW04_02
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    HW04_02
截止日期    2016年4月27日

简述：
用条件编译方法来编写程序。输入一行电报文字，可以任选两种输出：一为原文输出；
二为变换字母的大小写（如小写‘a’变成大写‘A’，大写‘D’变成小写‘d’），
其他字符不变。用#define命令控制是否变换字母的大小写。
例如，#define CHANGE 1 则输出变换后的文字，若#define CHANGE 0则原文输出。

输入：
hello !
world !
hello world!
abcd
0j$MmKmKgFee:rOiN2vCuSHB94?Ir'XK)b#1$>"B5]?[@ZN:{4>.R:15R}KX=n$|0=xm
uQ;v$2?,$dt>.u$f]*5co?wVee>w\4)fJa7SEbMI)9oD!iYNmO=?3g>Xmo)664
!9rCWvM,_&%t^;6&l^Pbi*iiqXzGGBx#.`+T*)yoZ6!-"x(b`j\pQu,</pre></p><h4>样例输出</h4><p><pre>hello !
WORLD !
hello world!
ABCD
0j$MmKmKgFee:rOiN2vCuSHB94?Ir'XK)b#1$>"B5]?[@ZN:{4>.R:15R}KX=n$|0=xm
Uq;V$2?,$DT>.U$F]*5CO?WvEE>W\4)FjA7seBmi)9Od!IynMo=?3G>xMO)664
!9RcwVm,_&%T^;6&L^pBI*IIQxZggbX#.`+t*)YOz6!-"X(B`J\PqU,
******************************************************************************/

#include<stdio.h>
#include<string.h>
#define CHANGE c%2

void Conversion();


char s[100];
int len;
int count = 0;
int i;

int main()
{
	while (fgets(s,100,stdin))
	{
		len = strlen(s) ;
		char c= s[0];
		if (CHANGE == 0)
		{
			printf("%s", s);
		}
		else
		{
			Conversion();
		}
	}
}

void Conversion()
{
	for (int i = 0; i < len; i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
		}
	}
	printf("%s", s);
}

