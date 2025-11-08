#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

char ** luo_kertotaulu_mjt(uint a, uint b, uint c, uint d)
{
    uint i, j, k, x, m, tmp, pituus=0, koko=0, laskuri=0;

    char **rivit = malloc((d-c+2)*sizeof(char*));

    uint *leveydet = malloc((b-a+2)*sizeof(uint));

    for(j=0; j<b-a+2;j++)
    {
        if(j==0)
        {
            tmp=d;
        }
        else
        {
            tmp=(d*(a+j-1));
        }
        while(tmp!=0)
        {
            tmp/=10;
            pituus++;
        }
        leveydet[j]=pituus;
        koko+=pituus+1;
        pituus=0;
    }

    for(j=0; j<d-c+2; j++)
    {
        rivit[j]=malloc(koko*sizeof(char));
    }

    for(i=0; i<d-c+2; i++)
    {
        laskuri=0;
        for(j=0; j<b-a+2; j++)
        {
            m=leveydet[j];
            if(i==0 && j==0)
            {
                for(k=0; k<leveydet[0]+1; k++)
                {
                    pituus=sprintf(&rivit[i][laskuri], " ");
                    laskuri+=pituus;
                }
                continue;
            }
            else if(j==0)
            {
                x=c+i-1;
            }
            else if(i==0)
            {
                x=a+j-1;
            }
            else
            {
                x=(c+i-1)*(a+j-1);
            }
            pituus=sprintf(&rivit[i][laskuri], "%*u", m, x);
            laskuri+=pituus;
            if(j!=b-a+1)
            {
                pituus=sprintf(&rivit[i][laskuri], " ");
                laskuri+=pituus;
            }
        }
    }

    free(leveydet);

    return rivit;
}
