/******************************************************************************
�� �� ��    HW03_01
��    ��    ���� 
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com 
��    ��    C���Գ������
�� ҵ ��    HW03_01
��ֹ����    2016��4��20��

������
 �ݹ�ʵ�����������������Լ��
******************************************************************************/


#include<stdio.h>
int MaxComDivisor(int a, int b);

int main()
{
	int a;
	int b;
	scanf("%d", &a);
	while (a != 0)
	{
		scanf("%d", &b);
		printf("%d\n", MaxComDivisor(a, b));
		scanf("%d", &a);
	}
	return 0;
}


int MaxComDivisor(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return MaxComDivisor(b, a%b);
	}
}
