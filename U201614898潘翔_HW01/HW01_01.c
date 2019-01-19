/******************************************************************************
文 件 名    HW01_01
作    者    潘翔 
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com 
课    程    C语言程序设计
作 业 号    习题2.2
截止日期    2016年3月3日（该日期为教师规定的作业提交截止日期）

简述：
  下面给出了一个简单C语言程序例程，用来完成以下工作：
1．输入华氏温度f，将它转换成摄氏温度c后输出；
2．输入圆的半径值ｒ，计算并输出圆的面积ｓ；
3．输入短整数ｋ、ｐ，将ｋ的高字节作为结果的低字节，ｐ的高字节作为结果的高字节，拼成一个新的整数，然后输出；
在这个例子程序中存在若干语法和逻辑错误。要求在计算机上对这个例子程序进行调试修改，使之能够正确完成指定任务。
******************************************************************************/
#include<stdio.h>
#define PI 3.14159
void main(void)
{
	int f;
	short p, k;
	double c, r, s;

	/* for task 1 */
	printf("Input  Fahrenheit:");
	scanf("%d", &f);
	c = (double)5 / 9 * (f - 32);
	printf("\n %d(F)=%.2f(C)\n\n", f, c);

	/* for task 2 */
	printf("input the radius r:");
	scanf("%lf", &r);
	s = PI * r * r;
	printf("\nThe acreage is %.2f\n\n", s);

	/* for task 3 */
	printf("input hex int k, p :");
	scanf("%hx %hx", &k, &p);
	short newint = (p & 0xff00) | (k & 0xff00) >> 8;
	printf("new int = %.4hx\n\n", newint);
	getchar(); 
}
