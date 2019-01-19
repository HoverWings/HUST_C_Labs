/*
设计一个含有年、月、日的日期结构类型，输入一个日期（年、月、日），存储在结构变量中，计算并输出该结构变量存储的日期是这一年的第几天。
输入：第一行为正整数N，表示有N组输入；接下来的N行，每行有3个正整数，分别表示年、月、日（正确的日期）。
输出：每行输入对应一行输出：表示第几天的正整数。
注意：必须使用结构变量保存日期，并对结构变量日期进行处理。否则作 “未完成” 处理。
*/
/*
样例输入
6
1604 5 1
1900 5 1
1600 5 1
2015 12 31
1600 2 20
2015 1 5
样例输出
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
	switch (month - 1)    //故意没有在case里加break
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