
/******************************************************************************
文 件 名	2源程序修改替换
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    2源程序修改替换
截止日期    2016年5月25日
简述：
给定一批整数，以0作为结束标志且不作为结点，将其建成一个先进先出的链表，先进先出链表的指头指针始终指向最先创建的结点（链头），
先建结点指向后建结点，后建结点始终是尾结点。
源程序中存在什么样的错误（先观察执行结果）？对程序进行修改、调试，使之能够正确完成指定任务。
******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
struct s_list
{
	int data; /* 数据域 */
	struct s_list *next; /* 指针域 */
};
void create_list(struct s_list *headp, int *p);
void main(void)
{
	struct s_list *head = NULL, *p;
	int s[] = { 1,2,3,4,5,6,7,8,0 }; /* 0为结束标记 */
	create_list(head, s); /* 创建新链表 */
	p = head; /*遍历指针p指向链头 */
	while (p) 
	{
		printf("%d\t", p->data); /* 输出数据域的值 */
		p = p->next; /*遍历指针p指向下一结点 */
	}
	printf("\n");
}
void create_list(struct s_list *headp, int *p)
{
	struct s_list * loc_head = NULL, *tail;
	if (p[0] == 0) /* 相当于*p==0 */
		;
	else { /* loc_head指向动态分配的第一个结点 */
		loc_head = (struct s_list *)malloc(sizeof(struct s_list));
		loc_head->data = *p++; /* 对数据域赋值 */
		tail = loc_head; /* tail指向第一个结点 */
		while (*p)
		{ /* tail所指结点的指针域指向动态创建的结点 */
			tail->next = (struct s_list *)malloc(sizeof(struct s_list));
			tail = tail->next; /* tail指向新创建的结点 */
			tail->data = *p++; /* 向新创建的结点的数据域赋值 */
		}
		tail->next = NULL; /* 对指针域赋NULL值 */
	}
	headp = loc_head; /* 使头指针headp指向新创建的链表 */
}
