/******************************************************************************
文 件 名	HW07_01
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    HW07_01
截止日期    2016年5月25日
简述：
8个中断服务程序，按优先级从高到低依次为：isr0、isr1、isr2、isr3、isr4、isr5、isr6、isr7。编写一个中断调度程序，要求如下：
①定义字段结构struct ISR_BITS，8个字段成员bit0、bit1、bit2、bit3、bit4、bit5、bit6、bit7各占1位(bit)，
其值分别用来表示在某个时刻系统是否调用相应的中断服务程序，比如，若biti(i=0,1,...,7)的值为1，则表示调用isri；值为0，则不调用。
②定义长度为8的函数指针数组p_isr，使每个元素p_isr[i]指向isri。
③根据字段结构变量的值，按优先级从高到低调用函数指针数组p_isr中相应元素所指向的中断服务程序，
即，首先判断bit0是否为1，若是，则调用p_isr[0]所指向的isr0；再依次判断bit1、...、bit7，做相应处理。
******************************************************************************/
/*
为了方便编程，可采用以下数据结构定义。
struct ISR_BITS
{
	unsigned int bit0: 1;
	unsigned int bit1: 1;
	unsigned int bit2: 1;
	unsigned int bit3: 1;
	unsigned int bit4: 1;
	unsigned int bit5: 1;
	unsigned int bit6: 1;
	unsigned int bit7: 1;
	unsigned int rsv : 8;
};

union ISR_REG 
{
	unsigned short &amp;nbsp;all;
	struct ISR_BITS bit;
};
void (*p_isr[8])(void);
以isr0为例，中断服务程序可简化为以下函数定义：
void isr0(void)<
{
	printf("The Interrupt Service Routine isr0 is called!");
}
定义union ISR_REG isr_reg; ,可从键盘输入isr_reg.all，实现对isr_reg.bit的8个字段成员赋值，据此按优先级调用中断服务程序。
输入：第一行为正整数N，表示有N个短整型数据需要处理，第二行为N个无符号短整形数。
输出：首先输出短整型数，再输出其中断处理结果。每个短整型的输出结束后，追加输出一个空行。
样例输入
5
56 0 255 8 89
样例输出
56:
The Interrupt Service Routine isr3 is called!
The Interrupt Service Routine isr4 is called!
The Interrupt Service Routine isr5 is called!

0:

255:
The Interrupt Service Routine isr0 is called!
The Interrupt Service Routine isr1 is called!
The Interrupt Service Routine isr2 is called!
The Interrupt Service Routine isr3 is called!
The Interrupt Service Routine isr4 is called!
The Interrupt Service Routine isr5 is called!
The Interrupt Service Routine isr6 is called!
The Interrupt Service Routine isr7 is called!

8:
The Interrupt Service Routine isr3 is called!

89:
The Interrupt Service Routine isr0 is called!
The Interrupt Service Routine isr3 is called!
The Interrupt Service Routine isr4 is called!
The Interrupt Service Routine isr6 is called!

*/
#include<stdio.h>

struct ISR_BITS 
{
	unsigned int bit0 : 1;
	unsigned int bit1 : 1;
	unsigned int bit2 : 1;
	unsigned int bit3 : 1;
	unsigned int bit4 : 1;
	unsigned int bit5 : 1;
	unsigned int bit6 : 1;
	unsigned int bit7 : 1;
	unsigned int rsv : 8;
};

union ISR_REG 
{
	unsigned short all;
	struct ISR_BITS bit;
};

void isr0() 
{
	printf("The Interrupt Service Routine isr0 is called!\n");
}
void isr1() 
{
	printf("The Interrupt Service Routine isr1 is called!\n");
}
void isr2() 
{
	printf("The Interrupt Service Routine isr2 is called!\n");
}
void isr3() 
{
	printf("The Interrupt Service Routine isr3 is called!\n");
}
void isr4() 
{
	printf("The Interrupt Service Routine isr4 is called!\n");
}
void isr5() 
{
	printf("The Interrupt Service Routine isr5 is called!\n");
}
void isr6() 
{
	printf("The Interrupt Service Routine isr6 is called!\n");
}
void isr7() 
{
	printf("The Interrupt Service Routine isr7 is called!\n");
}

void(*p_isr[8])() = { isr0,isr1,isr2,isr3,isr4,isr5,isr6,isr7 };

int main()
{
	int N;
	scanf("%d", &N);
	union ISR_REG irArray[10];
	for (int i = 0; i < N; ++i)
	{
		scanf("%hu", &irArray[i].all);
	}
	for (int i = 0; i < N; i++)
	{
		printf("%hu:\n", irArray[i].all);
		if (irArray[i].bit.bit0)p_isr[0]();
		if (irArray[i].bit.bit1)p_isr[1]();
		if (irArray[i].bit.bit2)p_isr[2]();
		if (irArray[i].bit.bit3)p_isr[3]();
		if (irArray[i].bit.bit4)p_isr[4]();
		if (irArray[i].bit.bit5)p_isr[5]();
		if (irArray[i].bit.bit6)p_isr[6]();
		if (irArray[i].bit.bit7)p_isr[7]();
		printf("\n");
	}
	return 0;
}