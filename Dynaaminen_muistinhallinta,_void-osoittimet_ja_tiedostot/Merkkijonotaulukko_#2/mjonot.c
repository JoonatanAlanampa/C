#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "mjonot.h"

char ** jarjesta_mjt(char **mjt, size_t lkm, int (*vrt)(const char*, const char *))
{
    size_t pituus;
    int i, j;
    char *tmp;
    char **t = malloc(lkm*sizeof(char *));

    for(i=0; i<lkm; i++)
    {
        pituus = strlen(mjt[i])+1;
        t[i] = malloc(pituus*sizeof(char));
        for(j=0; j<pituus; j++)
        {
            t[i][j] = mjt[i][j];
        }
    }

    for(i=0; i<lkm-1; i++)
    {
        for(j=i+1; j<lkm; j++)
        {
            if(vrt(t[i], t[j])==0)
            {
                tmp=t[i];
                t[i]=t[j];
                t[j]=tmp;
            }
        }
    }

    return t;
}
