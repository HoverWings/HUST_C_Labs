/******************************************************************************
�� �� ��	HW07_01
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    HW07_01
��ֹ����    2016��5��25��
������
8���жϷ�����򣬰����ȼ��Ӹߵ�������Ϊ��isr0��isr1��isr2��isr3��isr4��isr5��isr6��isr7����дһ���жϵ��ȳ���Ҫ�����£�
�ٶ����ֶνṹstruct ISR_BITS��8���ֶγ�Աbit0��bit1��bit2��bit3��bit4��bit5��bit6��bit7��ռ1λ(bit)��
��ֵ�ֱ�������ʾ��ĳ��ʱ��ϵͳ�Ƿ������Ӧ���жϷ�����򣬱��磬��biti(i=0,1,...,7)��ֵΪ1�����ʾ����isri��ֵΪ0���򲻵��á�
�ڶ��峤��Ϊ8�ĺ���ָ������p_isr��ʹÿ��Ԫ��p_isr[i]ָ��isri��
�۸����ֶνṹ������ֵ�������ȼ��Ӹߵ��͵��ú���ָ������p_isr����ӦԪ����ָ����жϷ������
���������ж�bit0�Ƿ�Ϊ1�����ǣ������p_isr[0]��ָ���isr0���������ж�bit1��...��bit7������Ӧ����
******************************************************************************/
/*
Ϊ�˷����̣��ɲ����������ݽṹ���塣
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
��isr0Ϊ�����жϷ������ɼ�Ϊ���º������壺
void isr0(void)<
{
	printf("The Interrupt Service Routine isr0 is called!");
}
����union ISR_REG isr_reg; ,�ɴӼ�������isr_reg.all��ʵ�ֶ�isr_reg.bit��8���ֶγ�Ա��ֵ���ݴ˰����ȼ������жϷ������
���룺��һ��Ϊ������N����ʾ��N��������������Ҫ�����ڶ���ΪN���޷��Ŷ���������
������������������������������жϴ�������ÿ�������͵����������׷�����һ�����С�
��������
5
56 0 255 8 89
�������
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