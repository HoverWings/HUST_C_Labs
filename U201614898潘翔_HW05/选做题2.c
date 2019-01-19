/******************************************************************************
文 件 名    选做题2 
作    者    潘翔
班    级	物联网1601
学    号    U201614898
邮    箱    1007458378@qq.com
课    程    C语言程序设计
作 业 号    选做题2
截止日期    2016年5月4日

简述：
八皇后问题 
******************************************************************************/

#include <stdio.h>
#define N 8
int quine[N] = {0}, count = 0;//count计数出现多少次
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
            quine[line] = arrage;	//第几行的quene
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
        //如果两个皇后在同一行、同一列或两条对角线上，则说明该位置错误
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
    for (i = 0; i < 8; i++) {	//实现赋值· 
        a[i][quine[i]] = 1;
    }
    for (i = 0; i < 8; i++) {
        int j;
        for (j = 0; j < 8; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("这是第%d组解决方案\n", count);
    printf("------\n");
}

