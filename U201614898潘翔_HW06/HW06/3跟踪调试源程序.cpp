#include "stdio.h"
char *strcpy(char *s, char *t);
void main(void)
{
	char a[20], b[60] = "there is a boat on the lake.";
	printf("%s\n", strcpy(a, b));
}
char *strcpy(char *s, char *t)
{
	char *p = s;
	while ((*p++ = *t++) != '\0');
	return (s);
}

