/******************************************************************************
�� �� ��    2Դ���������޸��滻_01
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    2Դ���������޸��滻_01
��ֹ����    2016��5��11��

������
Դ���������޸��滻
����ĳ���ͨ������ָ��Ͳ˵�ѡ���������ַ��������������ַ������Ӻ����������»��ߴ���д���ʵı��ʽ����䡢�����Ƭ�������Ƹó���
******************************************************************************/

#include "stdio.h"
#include "string.h"
void main(void)
{
	char *(*p)(char *a, const char *b);
	char a[80], b[80], c[160], *result = c;
	int choice, i;
	do {
		printf("\t\t1 copy string.\n");
		printf("\t\t2 connect string.\n");
		printf("\t\t3 exit.\n");
		printf("\t\tinput a number (1-3) please!\n");
		scanf("%d", &choice);
	} while (choice<1 || choice>3);
	switch (choice) {
	case 1:
		p = strcpy;
		break;
	case 2:
		p = strcat;
		break;
	case 3:
		goto down;
	}
	getchar();
	printf("input the first string please!\n");
	i = 0;
	scanf("%s", a);
	printf("input the second string please!\n");
	i = 0;
	scanf("%s", b);
	result = p(a, b);
	printf("the result is %s\n", result);
down:
	;
}
