/*
���нṹ��������struct Student{int num;char name[19]; double score;}; num��name��score�ֱ���ѧ�š��������ɼ������������������
��1��������3��Ԫ�صĽṹ����s���������������г�ʼ����ͬʱ����ṹָ��p��ʹ��ָ��s[0]��
��2������ָ��p�������������Ԫ�صĸ���Աֵ֮��
��3����ָ��p�������������Ԫ�صĸ���Աֵ֮(ѧ��������֮����tab������������������Ϊ20�������)��
���룺��һ��Ϊ������N����ʾ��N�����룻ÿ������������У���һ����һ��ѧ����Ϣ��<br />
�����ÿ�������Ӧһ�����
ע�⣺���ϸ�Ҫ��ʹ�ýṹ���ָ�룬���� ��δ��ɡ� ����
*/
/*
�������� 
2
20140101 ZhangChuanChao 88.88
20140119 XiDaDa 99.99
20140156 MeiMingZi 56
20140200 MaiDouDou 89.65
20140289 XiaoDouDou 86
20140210 DaoDaoDog 90.2
�������
20140101	ZhangChuanChao      88.880000
20140119	XiDaDa              99.990000
20140156	MeiMingZi           56.000000
20140101	ZhangChuanChao      88.880000
20140119	XiDaDa              99.990000
20140156	MeiMingZi           56.000000
20140200	MaiDouDou           89.650000
20140289	XiaoDouDou          86.000000
20140210	DaoDaoDog           90.200000
20140200	MaiDouDou           89.650000
20140289	XiaoDouDou          86.000000
20140210	DaoDaoDog           90.200000
*/
#include<stdio.h>
#include<string.h>
struct Student 
{
	int num;
	char name[19];
	double score; 
}typedef Student;

struct Group
{
	Student stu1;
	Student stu2;
	Student stu3;
}typedef Group;
Group group[10];
Student stu[20];
Group* p = &group[0];

int main()
{
	int N;
	scanf("%d",&N);
	int n = 3 * N;
	for (int i = 0;i < N; i++)
	{
		scanf("%d", &group[i].stu1.num);
		scanf("%s", group[i].stu1.name);
		scanf("%lf",&group[i].stu1.score);
		scanf("%d", &group[i].stu2.num);
		scanf("%s", group[i].stu2.name);
		scanf("%lf",&group[i].stu2.score);
		scanf("%d", &group[i].stu3.num);
		scanf("%s", group[i].stu3.name);
		scanf("%lf",&group[i].stu3.score);
		printf("%d\t", group[i].stu1.num);
		printf("%-20s", group[i].stu1.name);
		printf("%lf\n", group[i].stu1.score);
		printf("%d\t", group[i].stu2.num);
		printf("%-20s", group[i].stu2.name);
		printf("%lf\n", group[i].stu2.score);
		printf("%d\t", group[i].stu3.num);
		printf("%-20s", group[i].stu3.name);
		printf("%lf\n", group[i].stu3.score);	
		printf("%d\t", (p + i)->stu1.num);
		printf("%-20s", (p + i)->stu1.name);
		printf("%lf\n", (p + i)->stu1.score);
		printf("%d\t", (p + i)->stu2.num);
		printf("%-20s", (p + i)->stu2.name);
		printf("%lf\n", (p + i)->stu2.score);
		printf("%d\t", (p + i)->stu3.num);
		printf("%-20s", (p + i)->stu3.name);
		printf("%lf\n", (p + i)->stu3.score);
	}


	return 0;
}