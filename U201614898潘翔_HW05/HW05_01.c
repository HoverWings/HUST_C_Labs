/******************************************************************************
文 件 名    HW05_01
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    HW05_01
截止日期    2016年5月4日

简述：
编写一个程序，其功能要求是：输入n个学生的姓名（不超过100个学生，姓名字符数不大于20）和C语言课程的成绩，将成绩按照从高到低的次序排序，姓名同时作相应调整，输出排序后学生的姓名和C语言课程的成绩。然后，输入一个C语言课程成绩值，用二分查找进行搜索，如果查找到有该成绩，输出该成绩同学的姓名和C语言课程成绩；否则输出提示“Not found!”。
输入：第一行为正整数n，接下来的n行是n个学生和对应的成绩信息；然后是一个正整数N，表示需要查询N次，接下来的一行是N个需要查询的成绩。
输出：首先输出排序后的姓名和成绩信息，姓名和成绩用空格隔开，且姓名的宽度为20（左对齐，空格补齐）<span>；输出一个空行；然后是N行查询结果，若查询到则输出其姓名和成绩信息，格式与前者一致，否则输出“Not found!”。
注意：为了方便查找，成绩为正整数，且无重复成绩。


样例输入
5
ZhangChuanChao 88
XiaoHong 95
XiaoMing 90
LiSi 100
XiDaDa 83
4
90 88 83 59
样例输出
LiSi                 100
XiaoHong             95
XiaoMing             90
ZhangChuanChao       88
XiDaDa               83

XiaoMing             90
ZhangChuanChao       88
XiDaDa               83
Not found!

******************************************************************************/

#include<stdio.h>

int Resort(int begin, int end);
int Inquire(int score, int begin, int end);

struct Student
{
	char name[15];
	int score;//成绩
};

struct Student stu[20];

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	int result;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%d",stu[i].name,&stu[i].score);
		getchar();
	}
	Resort(1, n);
	for (int i = 1; i <= n; i++)
	{
		printf("%-20s %d\n", stu[i].name, stu[i].score);
	}
	printf("\n");
	int N;
	int temp_score;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &temp_score);
		Inquire(temp_score,1,n);

	}
	return 0;
}

int Resort(int begin, int end)
{

	if (begin == end)
	{
		return 0;
	}
	int maxi=begin;
	struct Student temp;
	for (int i = begin; i <= end; i++)
	{
		if (stu[i].score > stu[maxi].score)
		{
			maxi = i;
		}
	}
	temp = stu[begin];
	stu[begin] = stu[maxi];
	stu[maxi] = temp;
	return Resort(begin+1, end);
}

int Inquire(int score,int begin,int end)
{
	int flag=0;
	int half = (begin + end) / 2;
	if (begin >= end || stu[half].score == score)
	{
		if (score == stu[half].score)
		{
			printf("%-20s %d\n", stu[half].name, stu[half].score);
			return half;
		}
		else
		{
			printf("Not found!\n");
			return -1;
		}
	}
	if (begin < end)
	{
		if (stu[half].score>score)
		{
			return Inquire(score, half + 1, end);
		}
		else
		{
			return Inquire(score, begin, half);	
		}
	}
}


