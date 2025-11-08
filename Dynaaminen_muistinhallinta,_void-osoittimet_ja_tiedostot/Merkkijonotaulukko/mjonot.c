#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "mjonot.h"

char ** kopioi_mjt(char **mjt, size_t lkm)
{
    size_t pituus;
    int i, j;
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

    return t;
}
