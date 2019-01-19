#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool strnins(char s[], char t[], int n);

int main()
{
	char a[50] = "The adopted symbol is ", b[27] = "abcdefghijklmnopqrstuvwxyz";
	strnins(a, b, 5);
	printf("%s\n", a);
	return 0;
}


bool strnins(char s[], char t[], int n)
{
	char temp[100];
	if (n < 0 || n>strlen(s))
	{
		printf("Error!\n");
		return false;
	}
	strcpy(temp, s + n);
	strcpy(s+n, t);//t+n之后添加到s结尾处
	strcat(s, temp);

	return true;
}


