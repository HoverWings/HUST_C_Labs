/******************************************************************************
�� �� ��    HW05_01
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    HW05_01
��ֹ����    2016��5��4��

������
��дһ�������书��Ҫ���ǣ�����n��ѧ����������������100��ѧ���������ַ���������20����C���Կγ̵ĳɼ������ɼ����մӸߵ��͵Ĵ�����������ͬʱ����Ӧ��������������ѧ����������C���Կγ̵ĳɼ���Ȼ������һ��C���Կγ̳ɼ�ֵ���ö��ֲ��ҽ���������������ҵ��иóɼ�������óɼ�ͬѧ��������C���Կγ̳ɼ������������ʾ��Not found!����
���룺��һ��Ϊ������n����������n����n��ѧ���Ͷ�Ӧ�ĳɼ���Ϣ��Ȼ����һ��������N����ʾ��Ҫ��ѯN�Σ���������һ����N����Ҫ��ѯ�ĳɼ���
�����������������������ͳɼ���Ϣ�������ͳɼ��ÿո�������������Ŀ��Ϊ20������룬�ո��룩<span>�����һ�����У�Ȼ����N�в�ѯ���������ѯ��������������ͳɼ���Ϣ����ʽ��ǰ��һ�£����������Not found!����
ע�⣺Ϊ�˷�����ң��ɼ�Ϊ�������������ظ��ɼ���


��������
5
ZhangChuanChao 88
XiaoHong 95
XiaoMing 90
LiSi 100
XiDaDa 83
4
90 88 83 59
�������
LiSi                 100
XiaoHong             95
XiaoMing             90
ZhangChuanChao       88
XiDaDa               83

XiaoMing             90
ZhangChuanChao       88
XiDaDa               83
Not found!

******************************************************************************/

#include<stdio.h>

int Resort(int begin, int end);
int Inquire(int score, int begin, int end);

struct Student
{
	char name[15];
	int score;//�ɼ�
};

struct Student stu[20];

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	int result;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%d",stu[i].name,&stu[i].score);
		getchar();
	}
	Resort(1, n);
	for (int i = 1; i <= n; i++)
	{
		printf("%-20s %d\n", stu[i].name, stu[i].score);
	}
	printf("\n");
	int N;
	int temp_score;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &temp_score);
		Inquire(temp_score,1,n);

	}
	return 0;
}

int Resort(int begin, int end)
{

	if (begin == end)
	{
		return 0;
	}
	int maxi=begin;
	struct Student temp;
	for (int i = begin; i <= end; i++)
	{
		if (stu[i].score > stu[maxi].score)
		{
			maxi = i;
		}
	}
	temp = stu[begin];
	stu[begin] = stu[maxi];
	stu[maxi] = temp;
	return Resort(begin+1, end);
}

int Inquire(int score,int begin,int end)
{
	int flag=0;
	int half = (begin + end) / 2;
	if (begin >= end || stu[half].score == score)
	{
		if (score == stu[half].score)
		{
			printf("%-20s %d\n", stu[half].name, stu[half].score);
			return half;
		}
		else
		{
			printf("Not found!\n");
			return -1;
		}
	}
	if (begin < end)
	{
		if (stu[half].score>score)
		{
			return Inquire(score, half + 1, end);
		}
		else
		{
			return Inquire(score, begin, half);	
		}
	}
}


