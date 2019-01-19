#include <stdio.h>
enum month {Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};

int main(void)
{
    enum month m;
    int year=2000,NDays;
    char *MonthName[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

    printf("Year %d\n",year);
    for (m=Jan; m<=Jul; m++)
    {
        if((m+1)%2)
            NDays=31;
        else
            NDays=30;

        if(m==1)
            //ÈòÄêÅÐ¶Ï
            if((year%4 == 0 && year%100 != 0)||(year%400 == 0))
                NDays=29;
            else
                NDays=28;

        printf("%s\t%d\n",MonthName[m],NDays);
    }

    for (m=Aug; m<=Dec; m++)
    {
        if((m+1)%2)
            NDays=30;
        else
            NDays=31;

        printf("%s\t%d\n",MonthName[m],NDays);
    }
}
