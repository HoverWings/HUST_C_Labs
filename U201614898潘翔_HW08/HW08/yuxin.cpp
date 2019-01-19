#include <stdio.h>
void main(void)
{
	char s[200];
	FILE *fp1;
	fp1 = fopen("text1.txt", "a");
	int i = 0, flag = 0;
	fgets(s, 200, stdin);
	while (s[i] != '\n')
	{
		if (!flag)
		{
			if (s[i] >= 'a'&&s[i] <= 'z')
			{
				s[i] += 'A' - 'a';
				flag = 1;
			}
		}
		if (s[i] == ' ') flag = 0;
		
		fwrite(&s[i], sizeof(char), 1, fp1);
		i++;
	}
	fclose(fp1);
}