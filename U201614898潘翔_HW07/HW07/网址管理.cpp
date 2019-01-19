/*
设计一个能够描述上网网址的结构类型struct Web。它包含缩略名、全名、URL，然后构造对应的结构数组，
编程输入你常用的缩略名、全名、网址，并且按照缩略名排序（升序）。输出排序前后的信息。
输入：第一行为正整数n，表示有n个网址信息，接下来的n行是n个网址信息。
输出：输出排序前后的网址信息，排序前的与排序后的用空行隔开。缩略名宽度为20，全名宽度为40，无其它空格。
样例输入
5
HuaKeDa HuaZhongKeJiDaXue http://www.hust.edu.cn/
BaiDu BaiDuSouSuoWangZhan https://www.baidu.com/
HuaKeJiSuanJi HuaZhongKeJiDaXueJiSuanJiXueYuan http://cs.hust.edu.cn/
TianMao TianMaoGouWuShangCheng http://www.tmall.com/
DouBan DouBanYingPing http://www.douban.com/
样例输出
HuaKeDa             HuaZhongKeJiDaXue                       http://www.hust.edu.cn/
BaiDu               BaiDuSouSuoWangZhan                     https://www.baidu.com/
HuaKeJiSuanJi       HuaZhongKeJiDaXueJiSuanJiXueYuan        http://cs.hust.edu.cn/
TianMao             TianMaoGouWuShangCheng                  http://www.tmall.com/
DouBan              DouBanYingPing                          http://www.douban.com/

BaiDu               BaiDuSouSuoWangZhan                     https://www.baidu.com/
DouBan              DouBanYingPing                          http://www.douban.com/
HuaKeDa             HuaZhongKeJiDaXue                       http://www.hust.edu.cn/
HuaKeJiSuanJi       HuaZhongKeJiDaXueJiSuanJiXueYuan        http://cs.hust.edu.cn/
TianMao             TianMaoGouWuShangCheng                  http://www.tmall.com/
*/

#include<stdio.h>
#include<string.h>

void Resort(int begin, int end);

struct Website
{
	char slug[15];
	char name[50];
	char add[50];
}typedef Website;

Website web[20];
Website temp;

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%s", web[i].slug, web[i].name, web[i].add);
		//printf("%-20.20s%-40.40s%s\n", web[i].slug, web[i].name, web[i].add);
		getchar();
	}
	for (int i = 0; i < n; i++)
	{
		printf("%-20.20s%-40.40s%s\n", web[i].slug, web[i].name, web[i].add);
	}
	printf("\n");
	Resort(0,n);
	for (int i = 0; i < n; i++)
	{
		printf("%-20.20s%-40.40s%s\n", web[i].slug, web[i].name, web[i].add);
	}
	return 0;
}

void Resort(int begin, int end)
{
	int j, k;
	
	for (j = begin; j<end; j++)
	{
		for (k = j + 1; k<end; k++)
		{
			if (strcmp(web[j].slug, web[k].slug)>0)
			{
				temp = web[j];
				web[j] = web[k];
				web[k] = temp;
			}
		}
	}
}
