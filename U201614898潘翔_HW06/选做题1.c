/******************************************************************************
�� �� ��	ѡ����1
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    HW06_01
��ֹ����    2016��5��18��
������
����Nλ������MλС����N=20��M=10��������a,b����̼���a+b����������
�磺12345678912345678912.1234567891 + 98765432109876543210.0123456789
12345678912345678912.1234567891
98765432109876543210.0123456789
******************************************************************************/

#include<stdio.h>
#include<string.h>
char s1[110], s2[110];//����ַ�����ʽ
int num1[220], num2[220];//���������ʽ
char result[220];

void init();
void CharToNum(char *s, int *a);
void sum(char *result, int* num1, int* num2);
void print();

int main()
{
	while (scanf("%s %s", s1, s2) != EOF)
	{
		init(); 								//ÿ����һ�γ�ʼ������  
		CharToNum(s1, num1);
		CharToNum(s2, num2);
		sum(result, num1,num2);					//��λ��͹���   
		print();
	}
	return 0;
}


void init()//�������ʼ������
{
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(result, 0, sizeof(result));
}

void CharToNum(char *s, int *a)
{
	int len = strlen(s);
	int k;
	if (strchr(s, '.') != NULL)							//�ж�����С����   
		k = strchr(s, '.') - s;							//���С�����λ��   
	else
		k = len;										//��С����   
	for (int i = k + 1, j = 99; i<len; i++, j--)		//С�������Ĵ浽ǰ 
		a[j] = s[i] - '0';
	for (int i = k - 1, j = 100; i >= 0; i--, j++)		//С����ǰ��Ĵ�ŵ��� 
		a[j] = s[i] - '0';
}

void sum(char *result, int* num1,int* num2)
{
	int s, v = 0;
	for (int i = 0; i<220; i++)
	{
		s = num1[i] + num2[i] + v;
		result[i] = s % 10;
		v = s / 10;
	}
}

void print()
{
	int i = 220;
	while (result[i] == 0 && i >= 100)
	{
		i--;
	}
	int j = 0;
	while (result[j] == 0 && j<100)
	{
		j++;
	}
	if (i == 99 && j == 100)							//ȫ��������  
		printf("0\n");
	else
	{
		for (; i >= 100; i--)
		{
			printf("%d", result[i]);
		}
		if (j != 100)
		{
			printf(".");
		}
		for (int i = 99; i >= j; i--)
			printf("%d", result[i]);
		printf("\n");
	}
}










