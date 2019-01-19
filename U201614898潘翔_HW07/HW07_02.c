/******************************************************************************
�� �� ��	HW07_02
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    HW07_02
��ֹ����    2016��5��25��
������
ʹ��������һ�Ű༶�ɼ�����
����ÿ��ѧ����ѧ�ţ�С��15���ַ�����������С��20���ַ�����Ӣ��ߵ���ѧ����ͨ����C���Գ���������ſγ̵ĳɼ���float���ͣ�
���ú������ʵ�����й��ܣ� 
��1������ÿ��ѧ���ĸ�����Ϣ��
��2�����ÿ��ѧ���ĸ�����Ϣ�� 
��3���޸�ָ��ѧ����ָ������������ݣ����γ̳ɼ�����������޸ĺ�ÿ��ѧ���ĸ�����Ϣ��
��4��ͳ�Ʋ������λͬѧ���ſγ̵��ܳɼ���ƽ���ɼ��� 
��5������ƽ���ɼ������������򣬲����������������ʹ�ý����ڵ�������ͽ����ڵ�ָ�������ַ���ʵ�֣��ύʱֻ��ʹ������һ�֣� 
���룺
��1��ѧ���ɼ���Ϣ����һ��Ϊ������n����������n����n��ѧ������Ϣ��ÿ��ѧ������Ϣ����Ϊ ѧ�� ���� Ӣ��ɼ� ��ѧ�ɼ� ����ɼ� C���Գɼ���
��2���޸���Ϣ����һ��Ϊ������n����ʾ��n����Ϣ��Ҫ�޸ģ���������n����n���޸���Ϣ��ÿ���޸���Ϣ���� ѧ�� �γ��� �³ɼ��� 
��������е����������ѧ�ſ��Ϊ15���������Ϊ20���ɼ�������λС�����ҿ��Ϊ10��ȫ�������ո��� 
ÿ�������������׷�����һ�����С��������޸ġ�ͳ�ơ���������ǰ��������Ӧ�ı�ʶ�������������

��������
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
�������
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
		printf("�޷����ٿռ�!");
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
			printf("�޷����ٿռ�!");
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
	while (head != NULL)//������ӡ
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
		//����
		cur->scores[index] = score;
		cur = head;
	}
	printf("Alter:\n");
	printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", "ID", "Name", "English", "Math", "Physics", "C");
	while (head != NULL)//������ӡ
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
	while (head != NULL)//������ӡ
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
	while (head != NULL)//������ӡ
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

//����ʵ��ð������  
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
		for (int i = 0; i < length; i++) //��Ҫ����(n-1)�α���,���ƴ���  
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
			//ÿ�α���������pMove�����ƶ�������ͷ��  
			pMove = pNode;
		}
	}
	printf("Sort:\n");
	printf("%-15s%-20s%-10s\n", "ID","Name", "AVG");
	Student* head = pNode;
	while (head != NULL)//������ӡ
	{
		
		printf("%-15s%-20s%-10.2f", head->id, head->name,head->avg);
		printf("\n");
		head = head->next;
	}
	printf("\n");
	return pNode;
}





