/******************************************************************************
�� �� ��    2�滻��
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    1�Ĵ���
��ֹ����    2016��4��27��

������
Դ�����޸��滻��
******************************************************************************/
#include<stdio.h>
#define MAX(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))
float sum(float x, float y);
float f;
void main(void)
{
	int a, b, c;
	float d, e;
	int m;
	printf("Enter three integers:");
	scanf("%d%d%d", &a, &b, &c);
	printf("\nthe maximum of them is %d\n", MAX(a, b, c));
	printf("Enter two floating point numbers:");
	scanf("%f%f", &d, &e);
	printf("\nthe sum of them is  %f\n", sum(d, e));
}


float sum(float x, float y)
{
	return x+y;
}
