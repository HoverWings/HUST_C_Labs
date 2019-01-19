/******************************************************************************
文 件 名	HW06_02
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    HW06_02
截止日期    2016年5月18日

简述：
利用大小为n的指针数组指向用gets函数输入的n行，每行不超过80个字符。
编写一个函数，它将每一行中连续的多个空格字符压缩为一个空格字符。在调用函数中输出压缩空格后的各行，空行不予输出。
3
   zhang    chuan  chao

xi da da
4
If only we'd stop trying to be happy
we'd have a pretty good time.


0
把接下来的读入拼接到一起
******************************************************************************/

#include<stdio.h>
#include<string.h>
void fun(char len[][80], int i);

int main()
{
	int n;
	char len[20][80];
	int i;//代表行数
	while (scanf("%d", &n), n)
	{
		getchar();
		for (int i = 1; i <= n; i++)
		{
			fgets(len[i], 500, stdin);
			if (len[i][0] != '0'&& len[i][0] != '\n')
			{
				fun(len, i);
			}		
		}
		printf("\n");
	}

	return 0;
}

void fun(char len[][80],int i)
{
	int length=strlen(len[i])-1;
	char c = 0, flag = 0;
	for (int j = 0; j<length; j++)
	{
		c = len[i][j];
		if (c == ' ')
		{
			if (flag == 0)
			{
				flag = 1;
			}
			else
			{
				continue;
			}
		}
		else
		{
			flag = 0;
		}
		printf("%c", c);
	}
	printf("\n");
}

