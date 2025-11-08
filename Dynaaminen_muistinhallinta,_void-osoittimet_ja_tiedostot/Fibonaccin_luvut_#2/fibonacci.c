#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fibonacci.h"

char * fib_jono_mj(unsigned int n)
{
    int i, tmp, pituus=0, alku1=0, alku2=1, summa, kap=1, pit=0, m;

    char *loppujono = malloc(kap);

    if(n==0)
    {
        loppujono[0] = '\0';
        pit++;
        return loppujono;
    }

    if(n!=1)
    {
        m=4;
        while(pit+m>kap)
        {
            kap = 2*kap;
            if(kap==4)
            {
                continue;
            }
            loppujono = realloc(loppujono, kap);
        }
        pit+=sprintf(&loppujono[pit], "%d, ", alku1);
        if(n!=2)
        {
            m=4;
            while(pit+m>kap)
            {
                kap = 2*kap;
                loppujono = realloc(loppujono, kap);
            }
            pit+=sprintf(&loppujono[pit], "%d, ", alku2);
        }
        else
        {
            m=2;
            while(pit+m>kap)
            {
                kap = 2*kap;
                loppujono = realloc(loppujono, kap);
            }
            pit+=sprintf(&loppujono[pit], "%d", alku2);
        }
    }
    else
    {
        m=2;
        while(pit+m>kap)
        {
            kap = 2*kap;
            loppujono = realloc(loppujono, kap);
        }
        pit+=sprintf(&loppujono[pit], "%d", alku1);
    }

    for(i=3; i<=n; i++)
    {
        tmp=i;
        while(tmp!=0)
        {
            tmp/=10;
            pituus++;
        }

        if(i+1==n+1)
        {
            summa=alku1+alku2;
            m=pituus+1;
            while(pit+m>kap)
            {
                kap = 2*kap;
                loppujono = realloc(loppujono, kap);
            }
            pit+=sprintf(&loppujono[pit], "%d", summa);
            alku1=alku2;
            alku2=summa;
        }
        else
        {
            summa=alku1+alku2;
            m=pituus+3;
            while(pit+m>kap)
            {
                kap = 2*kap;
                loppujono = realloc(loppujono, kap);
            }
            pit+=sprintf(&loppujono[pit], "%d, ", summa);
            alku1=alku2;
            alku2=summa;
        }
        pituus=0;
    }

    loppujono = realloc(loppujono, pit+1);

    return loppujono;
}
