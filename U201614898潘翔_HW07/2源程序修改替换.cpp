/******************************************************************************
�� �� ��	2Դ�����޸��滻
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    2Դ�����޸��滻
��ֹ����    2016��5��25��
������
����һ����������0��Ϊ������־�Ҳ���Ϊ��㣬���佨��һ���Ƚ��ȳ��������Ƚ��ȳ������ָͷָ��ʼ��ָ�����ȴ����Ľ�㣨��ͷ����
�Ƚ����ָ��󽨽�㣬�󽨽��ʼ����β��㡣
Դ�����д���ʲô���Ĵ����ȹ۲�ִ�н�������Գ�������޸ġ����ԣ�ʹ֮�ܹ���ȷ���ָ������
******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
struct s_list
{
	int data; /* ������ */
	struct s_list *next; /* ָ���� */
};
struct s_list* create_list(struct s_list *headp, int *p);
void main(void)
{
	struct s_list *head = NULL, *p;
	int s[] = { 1,2,3,4,5,6,7,8,0 };			/* 0Ϊ������� */
	head=create_list(head, s);						/* ���������� */
	p = head;									/*����ָ��pָ����ͷ */
	while (p) 
	{
		printf("%d\t", p->data);				/* ����������ֵ */
		p = p->next;							/*����ָ��pָ����һ��� */
	}
	printf("\n");
}
struct s_list* create_list(struct s_list *headp, int *p)
{
	struct s_list * loc_head = NULL, *tail;
	if (p[0] == 0)								/* �൱��*p==0 */											 //���������Ϊ��
		;
	else 
	{											/* loc_headָ��̬����ĵ�һ����� */
		loc_head = (struct s_list *)malloc(sizeof(struct s_list));
		loc_head->data = *p++;					/* ��������ֵ */
		loc_head->next = NULL;
		tail = loc_head;						/* tailָ���һ����� */
		while (*p)																							//p����ֵ
		{										/* tail��ָ����ָ����ָ��̬�����Ľ�� */
			tail= (struct s_list *)malloc(sizeof(struct s_list));
			tail->next = loc_head;				/* tailָ���´����Ľ�� */
			tail->data = *p++;					/* ���´����Ľ���������ֵ */
			loc_head = tail;
		}
		//tail->next = NULL;					/* ��ָ����NULLֵ */
	}
	headp = loc_head;							/* ʹͷָ��headpָ���´��������� */
	return headp;
}





