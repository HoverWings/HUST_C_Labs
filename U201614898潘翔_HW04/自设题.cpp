#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MEM(a,x) memset(a,x,sizeof(a))   
using namespace std;
const int MAXN = 1000010;
bool visit[MAXN];
bool remainder[MAXN];
int main()
{
	int t;
	int n;
	int  num[310];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(visit, 0, sizeof(visit));
		int maxNum = 0;
		int i;
		for(i = 0; i < n;  i++)
		{
			scanf("%d",&num[i]);
		}
		int j;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				visit[abs(num[i] - num[j])] = true;
			}
		}
	
		for(i = 1;  ; i++)
		{

			if(!visit[i])
			{
			//	cout<<"i= "<<i<<endl;
					MEM(remainder,0);
					bool flag = true;
				for(j = 0; j < n; j++)
				{
					if(remainder[num[j] % i] == true)
					{
						flag = false;
						break;
					
					}
						remainder[num[j] % i] = true;
					
				}
				if(flag == true)
				{
					printf("%d\n",i);
					break;
				}
				
			}
		}
	}
	return 0;
}

