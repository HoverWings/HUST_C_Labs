/*
描述
输入一个长度无限制超长字符串，用一个先进先出，且每个节点接受一个输入字符的单向链表接收这个字符串。然后遍历并输出链表中的所有字符。将该超长字符串无冗余（不多分配一个字节的存储空间）地存放到一个通过动态存储分配创建的字符数组中，并且通过printf函数输出该超长字符串。
输入：一个超长字符串，以EOF结束。<br / >
输出：输出遍历链表的结果，空行(" ")，存入字符数组后的结果,回车换行(" ")
注意：请严格使用链表和动态内存分配，否则按 “未完成” 处理。<br / >
Hello! How are you!#
Hello! How are you!

Hello! How are you!
*/

#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct String
{
	char ch;
	struct String *next;
}String;

String* CreateString();
int PrintString(String *head);
char * SaveToArray(String * p, int length);




int main()
{
	String* head;
	int length;
	head= CreateString();
	length =PrintString(head);
	printf("\n");
	SaveToArray(head, length);
	printf("\n");
}


String* CreateString()
{
	char c;
	String* head;
	String* cur_1;
	if ((head = (String*)malloc(sizeof(String))) == NULL)
	{
		printf("无法开辟空间!");
		return head;
	}
	head->ch = '\0';
	head->next = NULL;
	String* pre;
	pre = head;
	String* cur;
	while ((c=getchar())!='#')
	{
		if ((cur = (String*)malloc(sizeof(String))) == NULL)
		{
			printf("无法开辟空间!");
			return head;
		}
		pre->next = cur;
		cur->ch = c;
		cur->next = NULL;
		pre = cur;
	}
	cur_1 = head->next;
	free(head);
	return cur_1;
}
int PrintString(String *head)
{
	int count=0;
	while (head!=NULL)//遍历打印
	{
		printf("%c", head->ch);
		count++;
		head = head->next;
	}
	return count;
}

char * SaveToArray(String * p,int length)
{
	int i = 0;
	char * array = (char*)malloc(sizeof(char));
	while (p != NULL) 
	{
		array = (char*)realloc(array, (i + 1) * sizeof(char));
		array[i] = p->ch;
		p = p->next;
		i++;
	}

	printf("\n");

	for (i = 0; i < length; ++i) 
	{
		printf("%c", array[i]);
	}
	return array;
}




