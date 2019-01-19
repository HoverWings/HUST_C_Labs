/******************************************************************************
文 件 名	HW06_03
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    HW06_03
截止日期    2016年5月18日

简述：
设某个班有N个学生，每个学生修了M门课程（用#define定义N、M，M=N=5）。
输入M门课程的名称。然后依次输入N个学生中每个学生所修的M门课程的成绩并且都存放到相应的数组中。编写下列函数： 
（1）计算每个学生各门课程平均成绩； 
（2）计算全班每门课程的平均成绩； 
（3）分别统计低于全班各门课程平均成绩的人数； 
（4）分别统计全班各门课程不及格的人数和90分以上（含90分）的人数； 
在调用函数中输出上面各函数的计算结果。
（要求都用指针操作，不得使用下标操作）
输入：第一行为5门课程的课程名；接下来每两行为一组，第一行为学生姓名，第二行为该学生对应的5门课程成绩。
输出：输出统计结果，具体格式见样例输出
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
void LowerThanAve(float *aveOfClasses, Student *p_stu, char classes[M + 1][20]);  //低于课程的平均分的人数
void FailNum(Student *p_stu, char classes[M + 1][20]);
void PerfectNum(Student *p_stu, char classes[M + 1][20]);



int main()
{
	Student stu[N+1];
	Student* p_stu = stu;
	char classes[M+1][20];
	float aveOfClass[M+1];//课程成绩
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
	for (int i = 1; i <= N; i++)//每一个学生平均成绩
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

void LowerThanAve(float *aveOfClasses, Student *p_stu,char classes[M + 1][20])  //低于课程的平均分的人数
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









