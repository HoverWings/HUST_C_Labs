/******************************************************************************
文 件 名	选做题2
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    选做题2
截止日期    2016年5月18日
简述：
编写使用复杂声明char *(*p[2])(const char *,const char *);的程序。
提示：p中元素可为strcmp、strstr等函数名。
******************************************************************************/
#include <stdio.h>
#include <string.h>


int main() 
{
	char* (__cdecl *p[2])(char * , char const* );
	p[0] = strcpy;
	p[1] = strstr;
	char test1[100] = "I AM AN IOTER";
	const char test2[100] = "i am an ioter";
	printf("%c\n", *(*p[0])(test1, test2));
	printf("%c\n", *(*p[1])(test1, test2));
	return 0;
}

