/******************************************************************************
�� �� ��    HW01_04
��    ��    ���� 
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com 
��    ��    C���Գ������
�� ҵ ��    ϰ��2.2
��ֹ����    2016��3��3�գ�������Ϊ��ʦ�涨����ҵ�ύ��ֹ���ڣ�

������
  IP��ַת�� 
******************************************************************************/
#include<stdio.h>



int main()
{
	int N;
	scanf("%d", &N);
	
	char str_ip_index[4] = { '\0' };
	unsigned long int IP;
	unsigned long int IP1;
	unsigned long int IP2;
	unsigned long int IP3;
	unsigned long int IP4;



	for (int i = 1; i <=N; i++)
	{
		scanf("%lu", &IP);
		IP1= ((IP & 0xff000000) >> 24);
		IP2 = ((IP & 0x00ff0000) >> 16);
		IP3 = ((IP & 0x0000ff00) >> 8);
		IP4 = ((IP & 0x000000ff));
		printf("%lu.%lu.%lu.%lu\n", temp4, temp3, temp2, temp1);
	}
	return 0;
}
