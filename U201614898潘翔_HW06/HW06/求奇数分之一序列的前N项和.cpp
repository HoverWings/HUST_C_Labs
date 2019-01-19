#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	double t=1;
	double S=0;
	for (int i = 1; i <= N; i++)
	{
		S += 1 / t;
		t = t + 2;
	}
	printf("sum = %.6lf\n", S);
	return 0;
}