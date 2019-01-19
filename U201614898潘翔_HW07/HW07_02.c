/******************************************************************************
文 件 名	HW07_02
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    HW07_02
截止日期    2016年5月25日
简述：
使用链表建立一张班级成绩单，
包括每个学生的学号（小于15个字符）、姓名（小于20个字符）、英语、高等数学、普通物理、C语言程序设计四门课程的成绩（float类型）
试用函数编程实现下列功能： 
（1）输入每个学生的各项信息。
（2）输出每个学生的各项信息。 
（3）修改指定学生的指定数据项的内容（各课程成绩），并输出修改后每个学生的各项信息。
（4）统计并输出各位同学四门课程的总成绩和平均成绩。 
（5）按照平均成绩进行升序排序，并输出排序结果。（请使用交换节点数据域和交换节点指针域两种方法实现，提交时只需使用其中一种） 
输入：
（1）学生成绩信息。第一行为正整数n，接下来的n行是n个学生的信息，每个学生的信息依次为 学号 姓名 英语成绩 数学成绩 物理成绩 C语言成绩。
（2）修改信息。第一行为正整数n，表示有n个信息需要修改，接下来的n行是n个修改信息，每个修改信息包含 学号 课程名 新成绩。 
输出：所有的输出，其中学号宽度为15，姓名宽度为20，成绩保留两位小数并且宽度为10，全部左对齐空格补齐 
每次输出结束后，再追加输出一个空行。并且在修改、统计、排序的输出前，加入相应的标识，见样例输出。

样例输入
5
U20140101 ZhangChuanChao 85 86 87 88
U20140126 MaiDouDou 99 99 99 99
U20140158 XiaoDouDou 56 85 89 59
U20140312 DaoDaoDog 84 89 65 100
U20140359 XiDaDa 88.8 88.8 88.8 88.8
3
U20140101 Math 95.6
U20140359 C 100
U20140359 English 100
样例输出
ID             Name                English   Math      Physics   C
U20140101      ZhangChuanChao      85.00     86.00     87.00     88.00
U20140126      MaiDouDou           99.00     99.00     99.00     99.00
U20140158      XiaoDouDou          56.00     85.00     89.00     59.00
U20140312      DaoDaoDog           84.00     89.00     65.00     100.00
U20140359      XiDaDa              88.80     88.80     88.80     88.80

Alter:
ID             Name                English   Math      Physics   C
U20140101      ZhangChuanChao      85.00     95.60     87.00     88.00
U20140126      MaiDouDou           99.00     99.00     99.00     99.00
U20140158      XiaoDouDou          56.00     85.00     89.00     59.00
U20140312      DaoDaoDog           84.00     89.00     65.00     100.00
U20140359      XiDaDa              100.00    88.80     88.80     100.00

SumAndAvg:
ID             Name                SUM       AVG
U20140101      ZhangChuanChao      355.60    88.90
U20140126      MaiDouDou           396.00    99.00
U20140158      XiaoDouDou          289.00    72.25
U20140312      DaoDaoDog           338.00    84.50
U20140359      XiDaDa              377.60    94.40

Sort:
ID             Name                AVG
U20140158      XiaoDouDou          72.25
U20140312      DaoDaoDog           84.50
U20140101      ZhangChuanChao      88.90
U20140359      XiDaDa              94.40
U20140126      MaiDouDou           99.00
******************************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include <stdlib.h>

typedef struct Student
{
	char id[15];
	char name[15];
	float scores[4];
	float sum;
	float avg;
	struct Student *next;
}Student;

Student* Create(int n);
void PrintAll(Student *head);
void AlterData(Student *head, int n);
void SumAndAvg(Student *head);
void swapDF(Student *A, Student *B);
void sawpPf(Student *A, Student *B, Student* head);
Student *Sort(Student *pNode, int length);

int main()
{
	Student* head;
	int n;
	scanf("%d", &n);
	int length = n;
	head = Create(n);
	PrintAll(head);
	scanf("%d", &n);
	AlterData(head, n);
	SumAndAvg(head);
	Sort(head, length);
	
}

Student* Create(int n)
{
	Student* head;
	Student* cur_1;
	if ((head = (Student*)malloc(sizeof(Student))) == NULL)
	{
		printf("无法开辟空间!");
		return head;
	}
	head->next = NULL;
	Student* pre;
	pre = head;
	Student* cur;
	for (int i = 1; i <= n; i++)
	{
		if ((cur = (Student*)malloc(sizeof(Student))) == NULL)
		{
			printf("无法开辟空间!");
			return head;
		}
		pre->next = cur;
		scanf("%s %s %f %f %f %f", cur->id, cur->name, &cur->scores[0],&cur->scores[1], &cur->scores[2], &cur->scores[3]);
		cur->sum = 0;
		for (int j = 0;j < 4;j++)
		{
			cur->sum += cur->scores[j];
		}
		cur->avg = cur->sum / 4;
		cur->next = NULL;
		pre = cur;
	}
	cur_1 = head->next;
	free(head);
	return cur_1;
}

void PrintAll(Student *head)
{
	printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", "ID", "Name", "English", "Math", "Physics", "C");
	while (head != NULL)//遍历打印
	{	
		printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f", head->id,head->name, head->scores[0], head->scores[1],head->scores[2], head->scores[3]);
		printf("\n");
		head = head->next;
	}
	printf("\n");
}

void AlterData(Student *head,int n)
{
	int index;
	Student* cur = head;
	char id[15];
	char project[15];
	float score;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s %s %f", id, project, &score);
		if (!strcmp(project, "English")) 
		{
			index = 0;
		}
		else
		{
			if (!strcmp(project, "Math"))
			{
				index = 1;
			}
			else 
			{
				if (!strcmp(project, "Physics"))
				{
					index = 2;
				}
				else
				{
					if (!strcmp(project, "C"))
					{
						index = 3;
					}
				}
			} 
		}
		while (strcmp(id, cur->id))
		{
			cur = cur->next;
		}
		//操作
		cur->scores[index] = score;
		cur = head;
	}
	printf("Alter:\n");
	printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", "ID", "Name", "English", "Math", "Physics", "C");
	while (head != NULL)//遍历打印
	{
		printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f", head->id, head->name, head->scores[0], head->scores[1], head->scores[2], head->scores[3]);
		printf("\n");
		head = head->next;
	}
	printf("\n");
}

void SumAndAvg(Student *head)
{
	printf("SumAndAvg:\n");
	printf("%-15s%-20s%-10s%-10s\n", "ID","Name", "SUM", "AVG");
	while (head != NULL)//遍历打印
	{
		head->sum = 0;
		for (int j = 0; j < 4; j++)
		{
			head->sum += head->scores[j];
		}
		head->avg = head->sum / 4;
		printf("%-15s%-20s%-10.2f%-10.2f", head->id, head->name, head->sum,head->avg);
		printf("\n");
		head = head->next;
	}
	printf("\n");
}

void swapDF(Student *A,Student *B)
{
	Student* T;
	T = (Student*)malloc(sizeof(Student));
	strcpy(T->id, A->id);
	strcpy(A->id, B->id);
	strcpy(B->id, T->id);
	strcpy(T->name, A->name);
	strcpy(A->name, B->name);
	strcpy(B->name, T->name);
	for (int i = 0; i < 4; i++)
	{
		T->scores[i] = A->scores[i];
		A->scores[i] = B->scores[i];
		B->scores[i] = T->scores[i];
	}
	T->avg = A->avg;
	A->avg = B->avg;
	B->avg = T->avg;
	free(T);
}

void sawpPf(Student *A, Student *B,Student* head)
{
	Student* temp;
	Student* pre_A;
	Student* pre_B;
	while (head != NULL)//遍历打印
	{
		if (head->next == A)
		{
			pre_A = head;
		}
		if (head->next == B)
		{
			pre_B = head;
		}
		head = head->next;
	}
	temp = B->next;
	pre_A->next = B;
	B->next = A->next;
	pre_B->next = A;
	A->next = temp;
	printf("\n");
}

//链表实现冒泡排序  
Student *Sort(Student *pNode,int length) 
{
	if (pNode == NULL) 
	{
		printf("Error!");
		return NULL;
	}
	else 
	{

		Student *pMove;
		pMove = pNode;
		for (int i = 0; i < length; i++) //需要进行(n-1)次遍历,控制次数  
		{
			while (pMove->next != NULL) 
			{
				if (pMove->avg > pMove->next->avg)
				{
					
					/*sawpPf(pMove, pMove->next, pNode);*/
					/*temp = pMove->avg;
					pMove->avg = pMove->next->avg;
					pMove->next->avg = temp;*/
					swapDF(pMove, pMove->next);
				}
				pMove = pMove->next;
			}
			//每次遍历结束，pMove重新移动到链表头部  
			pMove = pNode;
		}
	}
	printf("Sort:\n");
	printf("%-15s%-20s%-10s\n", "ID","Name", "AVG");
	Student* head = pNode;
	while (head != NULL)//遍历打印
	{
		
		printf("%-15s%-20s%-10.2f", head->id, head->name,head->avg);
		printf("\n");
		head = head->next;
	}
	printf("\n");
	return pNode;
}





