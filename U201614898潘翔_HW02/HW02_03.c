/******************************************************************************
�� �� ��    HW02_03
��    ��    ���� 
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com 
��    ��    C���Գ������
�� ҵ ��    HW20_03
��ֹ����    2016��4��13��

������
 ������ת
******************************************************************************/


#include<stdio.h>
void NumReverse(int n);

int main()
{
	int n;
	scanf("%d", &n);
	while (n != 0) 
	{
		
		NumReverse(n);
		scanf("%d", &n);
	}
	return 0;

}

void NumReverse(int n)
{
	int ModNum = 0;// ����  
	int result = 0;
	while (n / 10 != 0) //һλ������ѭ��
	{

		ModNum = n % 10;
		n = n / 10;
		result = result * 10 + ModNum;
	}
	result=result * 10 + n;
	printf("%d\n", result);
}
