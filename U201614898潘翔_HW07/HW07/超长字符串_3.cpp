/*
����
����һ�����������Ƴ����ַ�������һ���Ƚ��ȳ�����ÿ���ڵ����һ�������ַ��ĵ��������������ַ�����Ȼ���������������е������ַ������ó����ַ��������ࣨ�������һ���ֽڵĴ洢�ռ䣩�ش�ŵ�һ��ͨ����̬�洢���䴴�����ַ������У�����ͨ��printf��������ó����ַ�����
���룺һ�������ַ�������EOF������<br / >
����������������Ľ��������(" ")�������ַ������Ľ��,�س�����(" ")
ע�⣺���ϸ�ʹ������Ͷ�̬�ڴ���䣬���� ��δ��ɡ� ����<br / >
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
//		//��������һ�ڵ�
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
		printf("2??����????����?????!");
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
			printf("2??����????����?????!");
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
	while (head->next!=NULL)//������ӡ
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



