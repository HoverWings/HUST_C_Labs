/*
���һ���ܹ�����������ַ�Ľṹ����struct Web����������������ȫ����URL��Ȼ�����Ӧ�Ľṹ���飬
��������㳣�õ���������ȫ������ַ�����Ұ����������������򣩡��������ǰ�����Ϣ��
���룺��һ��Ϊ������n����ʾ��n����ַ��Ϣ����������n����n����ַ��Ϣ��
������������ǰ�����ַ��Ϣ������ǰ�����������ÿ��и��������������Ϊ20��ȫ�����Ϊ40���������ո�
��������
5
HuaKeDa HuaZhongKeJiDaXue http://www.hust.edu.cn/
BaiDu BaiDuSouSuoWangZhan https://www.baidu.com/
HuaKeJiSuanJi HuaZhongKeJiDaXueJiSuanJiXueYuan http://cs.hust.edu.cn/
TianMao TianMaoGouWuShangCheng http://www.tmall.com/
DouBan DouBanYingPing http://www.douban.com/
�������
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
