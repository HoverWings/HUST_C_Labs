/*
���һ�������ꡢ�¡��յ����ڽṹ���ͣ�����һ�����ڣ��ꡢ�¡��գ����洢�ڽṹ�����У����㲢����ýṹ�����洢����������һ��ĵڼ��졣
���룺��һ��Ϊ������N����ʾ��N�����룻��������N�У�ÿ����3�����������ֱ��ʾ�ꡢ�¡��գ���ȷ�����ڣ���
�����ÿ�������Ӧһ���������ʾ�ڼ������������
ע�⣺����ʹ�ýṹ�����������ڣ����Խṹ�������ڽ��д��������� ��δ��ɡ� ����
*/
/*
��������
6
1604 5 1
1900 5 1
1600 5 1
2015 12 31
1600 2 20
2015 1 5
�������
122
121
122
365
51
5
*/

#include<stdio.h>
int count_d(int year, int month, int day);

struct Date
{
	int year;
	int month;
	int day;
	int d;
}typedef Date;

Date date[20];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &date[i].year, &date[i].month, &date[i].day);
		date[i].d=count_d(date[i].year, date[i].month, date[i].day);
	}
	return 0;
}


int count_d(int year,int month,int day)
{
	int d=0;
	switch (month - 1)    //����û����case���break
	{
	case 11:
		d += 30;
	case 10:
		d += 31;
	case 9:
		d += 30;
	case 8:
		d += 31;
	case 7:
		d += 31;
	case 6:
		d += 30;
	case 5:
		d += 31;
	case 4:
		d += 30;
	case 3:
		d += 31;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			d += 29;
		}
		else
		{
			d += 28;
		}
	case 1:
		d += 31;

	default:
		break;
	}
	printf("%d\n", d += day);
	return d;
}