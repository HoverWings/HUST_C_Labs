#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	char ch;
	FILE *fp;
	if (argc != 2)								//��������������ĸ���
	{
		printf("Argument error!\n");
		exit(-1);
	}
	//if ((fp = fopen(argv[1], "r")) == NULL) 
	if ((fp= freopen(argv[1], "r", stdin)) == NULL)
	{        /*fpָ��filename*/
		printf("Can't open %s file!\n", argv[1]);	/*
													argv[0] ָ��������е�ȫ·����
													argv[1] ָ����DOS��������ִ�г�������ĵ�һ���ַ���
													argv[2] ָ��ִ�г�������ĵڶ����ַ���
													...
													argv[argc]ΪNULL��*/
		exit(-1);
	}
	while ((ch = fgetc(fp))!= EOF)           /*��filename�ж��ַ�*/
		putchar(ch);					   /*����ʾ����д�ַ�*/
	fclose(fp);							 /*�ر�filename*/
	return 0;
}
