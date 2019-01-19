#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include <stdlib.h> 


 
typedef struct Student
{
	char id[15];
	char name[15];
	struct Subjects *sub_head;
	float sum;
	float avg;
	struct Student *next;
}Student;

typedef struct Subjects
{
	float score;
	struct Subjects *next;
}Subjects;

Student* stu_Create(int n);
Subjects* sub_Create(int n);
void PrintAll(Student *head);


int main()
{
	Student* head;
	int n;
	scanf("%d", &n);
	int length = n;
	head = stu_Create(n);
	PrintAll(head);
	return 0;
}

Student* stu_Create(int n)
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
		scanf("%s %s", cur->id, cur->name);
		cur->sub_head=sub_Create(4);
		Subjects *sub_cur = cur->sub_head;
		cur->sum = 0;
		/*for (int j = 0;j < 4;j++)
		{
			cur->sum += sub_cur->score;
			sub_cur = sub_cur->next;
		}
		cur->avg = cur->sum / 4;*/
		cur->next = NULL;
		pre = cur;
	}
	cur_1 = head->next;
	free(head);
	return cur_1;
}


Subjects* sub_Create(int n)
{
	Subjects* head;
	Subjects* head_1;
	if ((head = (Subjects*)malloc(sizeof(Subjects))) == NULL)
	{
		printf("无法开辟空间!");
		return head;
	}
	head->next = NULL;
	Subjects* pre;
	pre = head;
	Subjects* cur;
	for (int i = 1; i <= n; i++)
	{
		if ((cur = (Subjects*)malloc(sizeof(Subjects))) == NULL)
		{
			printf("无法开辟空间!");
			return head;
		}
		pre->next = cur;
		scanf("%f",&cur->score);
		cur->next = NULL;
		pre = cur;
	}
	head_1 = head->next;
	free(head);
	return head_1;
}

void PrintAll(Student *head)
{
	printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", "ID", "Name", "English", "Math", "Physics", "C");
	while (head != NULL)//遍历打印
	{
		printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f", head->id, head->name,
			head->sub_head->score,
			head->sub_head->next->score,
			head->sub_head->next->next->score,
			head->sub_head->next->next->next->score);
		printf("\n");
		head = head->next;
	}
	printf("\n");
}
