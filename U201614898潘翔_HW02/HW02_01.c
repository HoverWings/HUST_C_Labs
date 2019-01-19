/******************************************************************************
�� �� ��    HW01_01
��    ��    ���� 
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com 
��    ��    C���Գ������
�� ҵ ��    HW20_01
��ֹ����    2016��4��13��

������
 ţ�ٷ��󷽳̵Ľ��Ƹ�
******************************************************************************/


#include<stdio.h>
#include<math.h>
int a, b, c, d;
float Solve(float a, float b, float c, float d);

int main()
{
	a = 3; b = -4; c = -5; d = 13;
	printf("%lf\n", Solve(a, b, c, d));
	return 0;
}

float Solve(float a, float b, float c, float d)
{
	float x = 1, x0=2, f, f1;
	while (fabs(x - x0) >= 1e-5)
	{
		x0 = x;
		f = ((a*x0 + b)*x0 + c)*x0+d;
		f1 = (3 * a*x0 + 2 * b)*x0 + c;
		x = x0 - f / f1;
	}
	return x;
}
