/******************************************************************************
�� �� ��	ѡ����2
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    ѡ����2
��ֹ����    2016��5��18��
������
��дʹ�ø�������char *(*p[2])(const char *,const char *);�ĳ���
��ʾ��p��Ԫ�ؿ�Ϊstrcmp��strstr�Ⱥ�������
******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>

void init();
void CharToNum(char *s, int *a, int *n1, int *n2);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int symbol;


int(*a[4])(int a, int b) = { add,sub,mul,div };



char s[110];
int num1[220], num2[220];//���������ʽ
int n1, n2;
char result[220];

int main()
{
	init(); //ÿ����һ�γ�ʼ������  
	scanf("%s",s);
	CharToNum(s, num1,&n1,&n2);  
	printf("%d", a[symbol](n1, n2));
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a*b;
}
int  div(int a, int b)
{
	if (b != 0)
	{
		return a / b;
	}
	else
	{
		return -1;
	}
	
}

void init()//�������ʼ������
{
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(result, 0, sizeof(result));
}

void CharToNum(char *s, int *a, int *n1, int *n2)
{
	int k = 0;
	int len = strlen(s);
	if (strchr(s, '+') != NULL)
	{
		k = strchr(s, '+') - s;
		symbol = 0;
	}	
	if (strchr(s, '-') != NULL)
	{
		k = strchr(s, '-') - s;
		symbol = 1;
	}
	if (strchr(s, '*') != NULL)
	{
		k = strchr(s, '*') - s;
		symbol = 2;
	}	
	if (strchr(s, '/') != NULL)
	{
		k = strchr(s, '/') - s;
		symbol = 3;
	}
	for (int i = 0; i < k; i++)
	{
		num1[i]= s[i] - '0';
		*n1 += (int)pow(10, k - 1 - i)*num1[i];
	}
	for (int i = k+1; i < len; i++)
	{
		num2[i] = s[i] - '0';
		*n2 += (int)pow(10, len - 1 - i)*num2[i];
	}
}



