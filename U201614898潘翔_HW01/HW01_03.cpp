/******************************************************************************
文 件 名    HW01_03
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    习题2.2
截止日期    2016年3月3日（该日期为教师规定的作业提交截止日期）

简述：
  编写一个程序，输入字符ｃ，如果ｃ是大写字母，则将ｃ转换成对应的小写，否则ｃ的值不变，最后输出ｃ。
******************************************************************************/


#include<stdio.h>
int main()
{
	char c;
	c=getchar();
	c=c>='A'&&c<='Z'?c+32:c;
	putchar(c);
	return 0;
}
