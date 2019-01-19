/******************************************************************************
文 件 名    2源程序完善修改替换_01
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    2源程序完善修改替换_01
截止日期    2016年5月11日

简述：
源程序完善修改替换
下面的程序通过函数指针和菜单选择来调用字符串拷贝函数或字符串连接函数，请在下划线处填写合适的表达式、语句、或代码片段来完善该程序。
******************************************************************************/

#include "stdio.h"
#include "string.h"
void main(void)
{
	char *(*p)(char *a, const char *b);
	char a[80], b[80], c[160], *result = c;
	int choice, i;
	do {
		printf("\t\t1 copy string.\n");
		printf("\t\t2 connect string.\n");
		printf("\t\t3 exit.\n");
		printf("\t\tinput a number (1-3) please!\n");
		scanf("%d", &choice);
	} while (choice<1 || choice>3);
	switch (choice) {
	case 1:
		p = strcpy;
		break;
	case 2:
		p = strcat;
		break;
	case 3:
		goto down;
	}
	getchar();
	printf("input the first string please!\n");
	i = 0;
	scanf("%s", a);
	printf("input the second string please!\n");
	i = 0;
	scanf("%s", b);
	result = p(a, b);
	printf("the result is %s\n", result);
down:
	;
}
