/******************************************************************************
文 件 名    HW01_04
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    习题2.2
截止日期    2016年3月3日（该日期为教师规定的作业提交截止日期）

简述：
  IP地址转换 
******************************************************************************/
#include<stdio.h>



int main()
{
	int N;
	scanf("%d", &N);
	
	char str_ip_index[4] = { '\0' };
	unsigned long int IP;
	unsigned long int IP1;
	unsigned long int IP2;
	unsigned long int IP3;
	unsigned long int IP4;



	for (int i = 1; i <=N; i++)
	{
		scanf("%lu", &IP);
		IP1= ((IP & 0xff000000) >> 24);
		IP2 = ((IP & 0x00ff0000) >> 16);
		IP3 = ((IP & 0x0000ff00) >> 8);
		IP4 = ((IP & 0x000000ff));
		printf("%lu.%lu.%lu.%lu\n", temp4, temp3, temp2, temp1);
	}
	return 0;
}
