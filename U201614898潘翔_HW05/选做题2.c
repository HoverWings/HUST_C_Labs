/******************************************************************************
�� �� ��    ѡ����2 
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    ѡ����2
��ֹ����    2016��5��4��

������
�˻ʺ����� 
******************************************************************************/

#include <stdio.h>
#define N 8
int quine[N] = {0}, count = 0;//count�������ֶ��ٴ�
void print();
int judge(int line, int arrage);
void solve_quine(int line);
int main(int argc, const char * argv[]) 
{
    solve_quine(0);
    printf("%d\n", count);
    return 0;
}
void solve_quine(int line)
{
    int arrage;
    for (arrage = 0; arrage < N; arrage++) 
	{
        if (judge(line, arrage))
		 {
            quine[line] = arrage;	//�ڼ��е�quene
	        if (line == N-1) 
			{
	            count++;
	            print();
	            quine[line] = 0;
	            break;
	        }
        solve_quine(line + 1);
        }
    }
}
int judge(int line, int arrage){
    int above;
    for (above = 0; above < line; above++) {
        int value = quine[above];			//
        //��������ʺ���ͬһ�С�ͬһ�л������Խ����ϣ���˵����λ�ô���
        if (value == arrage) {
            return 0;
        }
        if ((above + value) == (line + arrage))
            return 0;
        if ((above - value) == (line - arrage))
            return 0;
    }
    return 1;
}

void print()
{
    int a[8][8];
    int i;
    for (i = 0; i < 8; i++)
	 {
        int j;
        for (j = 0; j < 8; j++)
		 {
            a[i][j] = 0;
        }
    }
    for (i = 0; i < 8; i++) {	//ʵ�ָ�ֵ�� 
        a[i][quine[i]] = 1;
    }
    for (i = 0; i < 8; i++) {
        int j;
        for (j = 0; j < 8; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("���ǵ�%d��������\n", count);
    printf("------\n");
}

