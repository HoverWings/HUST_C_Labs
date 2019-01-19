#include <stdio.h>

int main(void)

{
    char a=0x61,v;
    int k;

    v=a;
    k=0;

    while(v!=0)
    {
        k+=1;
        v&=(v-1);
    }

    printf("%d\n",k);
    return 0;
}
