#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "viikko.h"

void viikko(int pv, int kk, int vuosi)
{
    int i;
    time_t a = time(NULL);
    char tuloste[40];
    struct tm b = *localtime(&a);
    b.tm_mday = pv;
    b.tm_mon = kk-1;
    b.tm_year = vuosi-1900;

    mktime(&b);

    while(b.tm_wday!=1)
    {
        if(b.tm_wday==0)
        {
            b.tm_mday-=6;
        }
        else
        {
            b.tm_mday--;
        }
        mktime(&b);
    }

    for(i=0; i<7; i++)
    {
        strftime(tuloste, 40, "%A %d. %B %Y", &b);
        printf("%s\n", tuloste);
        b.tm_mday++;
        mktime(&b);
    }
}
