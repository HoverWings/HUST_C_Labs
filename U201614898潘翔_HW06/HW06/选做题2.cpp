/******************************************************************************
�� �� ��	ѡ����2
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    ѡ����2
��ֹ����    2016��5��18��
������
��дʹ�ø�������char *(*p[2])(const char *,const char *);�ĳ���
��ʾ��p��Ԫ�ؿ�Ϊstrcmp��strstr�Ⱥ�������
******************************************************************************/
#include <stdio.h>
#include <string.h>


int main() 
{
	char* (__cdecl *p[2])(char * , char const* );
	p[0] = strcpy;
	p[1] = strstr;
	char test1[100] = "I AM AN IOTER";
	const char test2[100] = "i am an ioter";
	printf("%c\n", *(*p[0])(test1, test2));
	printf("%c\n", *(*p[1])(test1, test2));
	return 0;
}

