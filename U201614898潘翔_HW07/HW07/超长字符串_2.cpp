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
#define LEN sizeof(String)

typedef struct String
{
	char ch;
	struct String *next;
}String;

String *Create();
void Print(String *head);
String *head = NULL;


int main()
{
	head=Create();
	Print(head);
	return 0;
}

String *Create()
{
	String *head;
	String *p1, *p2;
	while (1)
	{
		p1 = (struct String*)malloc(sizeof(String));
		//menu_print_in();
		if (scanf("%c", p1->ch) == EOF)
		{
			break;
		}
		p1->next = NULL;
		p2->next = p1;
		p2 = p1;
	}
	return(head);
}
void Print(String *head)
{
	struct String *pt;
	pt = head;
	do {
		printf("%c", pt->ch);
		pt = pt->next;
	} while (pt != NULL);
	printf("\n");
}


