/******************************************************************************
�� �� ��    1�Ĵ��� 
��    ��    ���� 
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com 
��    ��    C���Գ������
�� ҵ ��    1�Ĵ��� 
��ֹ����    2016��4��27��

������
 Դ����Ĵ� 
******************************************************************************/


#include <stdio.h> 
#define SUM a+b
#define DIF a-b
#define SWAP(a,b)  t=a;a=b;b=t
void main()
{
	int a;
	int b, t;
    printf("Input two integers a, b:");
    scanf("%d%d", &a,&b);
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d", SUM, (SUM)*(DIF));
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);
}

