/*
描述
输入一个长度无限制超长字符串，用一个先进先出，且每个节点接受一个输入字符的单向链表接收这个字符串。然后遍历并输出链表中的所有字符。将该超长字符串无冗余（不多分配一个字节的存储空间）地存放到一个通过动态存储分配创建的字符数组中，并且通过printf函数输出该超长字符串。
输入：一个超长字符串，以EOF结束。<br / >
输出：输出遍历链表的结果，空行(" ")，存入字符数组后的结果,回车换行(" ")
注意：请严格使用链表和动态内存分配，否则按 “未完成” 处理。<br / >
Every man dies. Not every man really lives.
Every man dies. Not every man really lives.

Every man dies. Not every man really lives.
*/

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct String
{
	char ch;
	struct String *next;
}String;


String* create();
void PrintString(String *head);
//void SaveToArray(String *head); 


int main()
{
	String* head;
	head=create();
	PrintString(head);
}

//String* SaveSring(String ** head)
//{
//	String *cur = NULL;
//	String *pre = NULL;
//	cur = (String*)malloc(sizeof(String));
//	pre = (String*)malloc(sizeof(String));
//	while (1)
//	{
//		cur = (String*)malloc(sizeof(String));
//		if (head == NULL)
//		{
//			*head = cur;
//		}
//		if (pre->next != NULL)
//		{
//			pre->next = cur;
//		}
//		pre = cur;
//		cur->next = NULL;
//		//更新至下一节点
//		scanf("%c", &cur->ch);
//
//		if (cur->ch == '\n')
//		{
//			cur->ch = '0';
//			cur->next = NULL;
//			break;
//		}
//	}
//	return *head;
//}

String* create()
{
	char c;
	String* head;
	if ((head = (String*)malloc(sizeof(String))) == NULL)
	{
		printf("2??ü·????ú′?????!");
		return head;
	}
	head->ch = '\0';
	head->next = NULL;

	String* pre;
	pre = head;
	String* cur;
	while (scanf("%c",&c)!=EOF)
	{
		if ((cur = (String*)malloc(sizeof(String))) == NULL)
		{
			printf("2??ü·????ú′?????!");
			return head;
		}
		pre->next = cur;
		cur->ch = c;
		cur->next = NULL;
		pre = cur;
	}
	return head;
}
void PrintString(String *head)
{
	while (head->next!=NULL)//遍历打印
	{
		head = head->next;
		printf("%c\n", head->ch);
	}
	printf("\n");
}

//
//void printList(stud *p)
//{
//	while (p->link)
//	{
//		p = p->link;
//		printf("%s\n", p->name);
//
//	}
//
//}



