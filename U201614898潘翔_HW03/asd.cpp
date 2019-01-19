#include <stdio.h>
#define CHANGE(c) (c%2)

int main()
{
char c;
int change=0;
int flag=1;
while((c=getchar())!=EOF)
{
if(flag)
{ flag=0;
if(CHANGE(c))
{change=1;}//printf("ok1\n");}
}

  if (c=='\n') {flag=1;change=0;}


    if(change)
    {
        if(c>='A'&&c<='Z')putchar(c+32);
        else if(c>='a'&&c<='z')putchar(c-32);
        else putchar(c);
    }
    else putchar(c);
    // printf("f:%d c:%d  ",flag,change );

    }
return 0;
}
