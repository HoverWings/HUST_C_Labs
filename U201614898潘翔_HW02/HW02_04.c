/******************************************************************************
�� �� ��    HW02_04
��    ��    ���� 
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com 
��    ��    C���Գ������
�� ҵ ��    HW20_04
��ֹ����    2016��4��13��

������
 ��������˰ 
******************************************************************************/


#include<stdio.h>
#include<stdbool.h>
#include<math.h>

void CountTax(double salary);
bool IsZero(double salary);

int main()
{
	double salary;
	scanf("%lf", &salary);
	while (!IsZero(salary))
	{
		CountTax(salary);
		scanf("%lf", &salary);
	}
	return 0;
}


void CountTax(double salary)
{
	//printf("%.6lf\n", salary);
	int n;
	double Tax;
	if (salary <= 1000)
	{
		n = 1;
	}
	if (1000 < salary&&salary <= 2000)//50
	{
		n = 2;
		
	}
	if (2000 < salary&&salary <= 3000)//100
	{
		n = 3;

	}
	if (3000 < salary&&salary <= 4000)//150
	{
		n = 4;

	}
	if (4000 < salary&&salary <= 5000)//200
	{
		n = 5;

	}
	if (5000 < salary)
	{
		n = 6;

	}
	switch (n)
	{
	case 1:Tax = 0; break;
	case 2:Tax = (salary-1000)*0.05; break;
	case 3:Tax = 50+(salary - 2000)*0.10; break;
	case 4:Tax = 150 + (salary - 3000)*0.15; break;
	case 5:Tax = 300 + (salary - 4000)*0.20; break;
	case 6:Tax = 500 + (salary - 5000)*0.25; break;
	default:
		break;
	}
	printf("%.6lf\n", Tax);
}

bool IsZero(double salary)
{
	if (fabs(salary - 0) < 0.000001)
	{
		return true;
	}
	else
	{
		return false;
	}
}

