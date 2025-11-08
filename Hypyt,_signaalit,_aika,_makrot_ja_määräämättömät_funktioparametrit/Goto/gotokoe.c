#include "gotokoe.h"

int max2D(int **t2d, int kork, int lev)
{
    int i = t2d[0][0], j=0, k=0;

    ALKUKORK:
        if(!(j<kork))
            goto LOPPU;
        k=0;
    ALKULEV:
        if(!(k<lev))
            goto OHIKORK;
        if(!(t2d[j][k] > i))
            goto OHILEV;
        i = t2d[j][k];
    OHILEV:
        k++;
        goto ALKULEV;
    OHIKORK:
        j++;
        goto ALKUKORK;
    LOPPU:
        return i;
}
