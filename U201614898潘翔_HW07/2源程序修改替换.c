
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
void create_list(struct s_list *headp, int *p);
void main(void)
{
	struct s_list *head = NULL, *p;
	int s[] = { 1,2,3,4,5,6,7,8,0 }; /* 0Ϊ������� */
	create_list(head, s); /* ���������� */
	p = head; /*����ָ��pָ����ͷ */
	while (p) 
	{
		printf("%d\t", p->data); /* ����������ֵ */
		p = p->next; /*����ָ��pָ����һ��� */
	}
	printf("\n");
}
void create_list(struct s_list *headp, int *p)
{
	struct s_list * loc_head = NULL, *tail;
	if (p[0] == 0) /* �൱��*p==0 */
		;
	else { /* loc_headָ��̬����ĵ�һ����� */
		loc_head = (struct s_list *)malloc(sizeof(struct s_list));
		loc_head->data = *p++; /* ��������ֵ */
		tail = loc_head; /* tailָ���һ����� */
		while (*p)
		{ /* tail��ָ����ָ����ָ��̬�����Ľ�� */
			tail->next = (struct s_list *)malloc(sizeof(struct s_list));
			tail = tail->next; /* tailָ���´����Ľ�� */
			tail->data = *p++; /* ���´����Ľ���������ֵ */
		}
		tail->next = NULL; /* ��ָ����NULLֵ */
	}
	headp = loc_head; /* ʹͷָ��headpָ���´��������� */
}
