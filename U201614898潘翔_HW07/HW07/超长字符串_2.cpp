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


