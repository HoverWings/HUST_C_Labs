/******************************************************************************
�� �� ��    HW02_05
��    ��    ���� 
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com 
��    ��    C���Գ������
�� ҵ ��    HW20_05
��ֹ����    2016��4��13��

������
 �ո��� ����ո��滻Ϊ1���ո� 
******************************************************************************/

#include<stdio.h>
#include<string.h>


int getline_(char s[], int lim);


int main()
{
	int N; 
	scanf("%d", &N);
	char c[20][100];
	for (int i = 1; i <= N; i++)
	{
		getline_(c[i],100);
		printf("%c", c[i][1]);
	}
}


int getline_(char s[], int lim)
{
	int c, i;
	i = 1;
	while ((c = getchar()) != EOF&&c != '\n'&& --lim>0)
	{
		s[i] = c;
	}
	if (c == '\n') 
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}









#include <stdio.h>
void main(void)
{
	int i, n, s = 1;
	printf("Please enter n:");
	scanf("%d", n);
	for (i = 1, i <= n, i++)
		s = s*i;
	printf("%d! = %d", n, s);
}
