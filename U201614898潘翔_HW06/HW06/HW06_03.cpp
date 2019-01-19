/******************************************************************************
�� �� ��	HW06_03
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    HW06_03
��ֹ����    2016��5��18��

������
��ĳ������N��ѧ����ÿ��ѧ������M�ſγ̣���#define����N��M��M=N=5����
����M�ſγ̵����ơ�Ȼ����������N��ѧ����ÿ��ѧ�����޵�M�ſγ̵ĳɼ����Ҷ���ŵ���Ӧ�������С���д���к����� 
��1������ÿ��ѧ�����ſγ�ƽ���ɼ��� 
��2������ȫ��ÿ�ſγ̵�ƽ���ɼ��� 
��3���ֱ�ͳ�Ƶ���ȫ����ſγ�ƽ���ɼ��������� 
��4���ֱ�ͳ��ȫ����ſγ̲������������90�����ϣ���90�֣��������� 
�ڵ��ú������������������ļ�������
��Ҫ����ָ�����������ʹ���±������
���룺��һ��Ϊ5�ſγ̵Ŀγ�����������ÿ����Ϊһ�飬��һ��Ϊѧ���������ڶ���Ϊ��ѧ����Ӧ��5�ſγ̳ɼ���
��������ͳ�ƽ���������ʽ���������
A B C D E
Zhang
87 88 77 87 95
Li
88 98 100 48 75
Wang
85 68 95 47 59
Han
86 89 75 85 88
Gan
87 68 87 89 100

Average score of Zhang is 86.80
Average score of Li is 81.80
Average score of Wang is 70.80
Average score of Han is 84.60
Average score of Gan is 86.20
Average score of A is 86.60
Average score of B is 82.20
Average score of C is 86.80
Average score of D is 71.20
Average score of E is 83.40
Number of students lower than avg of A is 2
Number of students lower than avg of B is 2
Number of students lower than avg of C is 2
Number of students lower than avg of D is 2
Number of students lower than avg of E is 2
Number of students A fail is 0
Number of students B fail is 0
Number of students C fail is 0
Number of students D fail is 2
Number of students E fail is 1
Number of students A perfect is 0
Number of students B perfect is 1
Number of students C perfect is 2
Number of students D perfect is 0
Number of students E perfect is 2
******************************************************************************/

#include<stdio.h>
#define M 5
#define N 5

typedef struct Student
{
	char name[20];
	int scores[M+1];
} Student;

void AveOfStudent(Student* p_stu);
void AveOfClasses(Student* p_stu, char classes[M+1][20], float *aveOfClasses);
void LowerThanAve(float *aveOfClasses, Student *p_stu, char classes[M + 1][20]);  //���ڿγ̵�ƽ���ֵ�����
void FailNum(Student *p_stu, char classes[M + 1][20]);
void PerfectNum(Student *p_stu, char classes[M + 1][20]);



int main()
{
	Student stu[N+1];
	Student* p_stu = stu;
	char classes[M+1][20];
	float aveOfClass[M+1];//�γ̳ɼ�
	float* p_aveOfClass = aveOfClass;
	for (int i = 1; i <= M; i++)
	{
		scanf("%s", classes[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", stu[i].name);
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &stu[i].scores[j]);
		}
	}
	for (int i = 1; i <= N; i++)//ÿһ��ѧ��ƽ���ɼ�
	{
		AveOfStudent(p_stu +i);	
	}
	AveOfClasses(p_stu, classes, aveOfClass);
	LowerThanAve(aveOfClass, p_stu, classes);
	FailNum(p_stu, classes); 
	PerfectNum(p_stu, classes);
	return 0;
}

void AveOfStudent(Student* p_stu)
{
	int sum=0;
	for (int k = 1; k <= M; k++) 
	{
		sum = sum + p_stu->scores[k];
	}
	printf("Average score of %s is %.2f\n", (*p_stu).name, (double)sum / M);
}


void AveOfClasses(Student* p_stu,char classes[M + 1][20], float *aveOfClasses)
{
	int  sum;
	for (int i = 1; i <= M; i++) 
	{
		sum = 0;
		for (int j = 1; j <= N; j++)
		{
			sum = sum + (*(p_stu+j)).scores[i];
		}
		aveOfClasses[i] = (double)sum / M;
		printf("Average score of %s is %.2f\n", classes[i], aveOfClasses[i]);
	}
}

void LowerThanAve(float *aveOfClasses, Student *p_stu,char classes[M + 1][20])  //���ڿγ̵�ƽ���ֵ�����
{
	int sum;
	for (int i = 1; i <=M; i++) 
	{
		sum = 0;
		for (int j = 1; j <= N; j++) 
		{
			if ((*(p_stu + j)).scores[i] < aveOfClasses[i])
			{
				sum++;
			}
		}
		printf("Number of students lower than avg of %s is %d\n", classes[i],sum);
	}
}

void FailNum(Student *p_stu, char classes[M + 1][20])
{
	int sum;
	for (int i = 1; i <= M; i++)
	{
		sum = 0;
		for (int j = 1; j <= N; j++)
		{
			if ((*(p_stu + j)).scores[i] < 60)
			{
				sum++;
			}
		}
		printf("Number of students %s fail is %d\n", classes[i], sum);
	}
}

void PerfectNum(Student *p_stu, char classes[M + 1][20])
{
	int sum;
	for (int i = 1; i <= M; i++)
	{
		sum = 0;
		for (int j = 1; j <= N; j++)
		{
			if ((*(p_stu+j)).scores[i] > 90)
			{
				sum++;
			}
		}
		printf("Number of students %s perfect is %d\n", classes[i],sum);
	}
}









