/******************************************************************************
�� �� ��	HW06_02
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    HW06_02
��ֹ����    2016��5��18��

������
���ô�СΪn��ָ������ָ����gets���������n�У�ÿ�в�����80���ַ���
��дһ������������ÿһ���������Ķ���ո��ַ�ѹ��Ϊһ���ո��ַ����ڵ��ú��������ѹ���ո��ĸ��У����в��������
3
   zhang    chuan  chao

xi da da
4
If only we'd stop trying to be happy
we'd have a pretty good time.


0
�ѽ������Ķ���ƴ�ӵ�һ��
******************************************************************************/

#include<stdio.h>
#include<string.h>
void fun(char len[][80], int i);

int main()
{
	int n;
	char len[20][80];
	int i;//��������
	while (scanf("%d", &n), n)
	{
		getchar();
		for (int i = 1; i <= n; i++)
		{
			fgets(len[i], 500, stdin);
			if (len[i][0] != '0'&& len[i][0] != '\n')
			{
				fun(len, i);
			}		
		}
		printf("\n");
	}

	return 0;
}

void fun(char len[][80],int i)
{
	int length=strlen(len[i])-1;
	char c = 0, flag = 0;
	for (int j = 0; j<length; j++)
	{
		c = len[i][j];
		if (c == ' ')
		{
			if (flag == 0)
			{
				flag = 1;
			}
			else
			{
				continue;
			}
		}
		else
		{
			flag = 0;
		}
		printf("%c", c);
	}
	printf("\n");
}

