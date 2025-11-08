#include <string.h>
#include <limits.h>
#include "anagrammit.h"

int anagrammeja(char mj1[], char mj2[])
{
    int i, pituus1=strlen(mj1), pituus2=strlen(mj2);
    int laskuri1[UCHAR_MAX+1] = {0};
    int laskuri2[UCHAR_MAX+1] = {0};

    for (i=0; i<pituus1; i++)
    {
        laskuri1[(unsigned char)mj1[i]]++;
    }

    for (i=0; i<pituus2; i++)
    {
        laskuri2[(unsigned char)mj2[i]]++;
    }

    for (i=0; i<=UCHAR_MAX; i++)
    {
        if (laskuri1[i]!=laskuri2[i])
        {
            return 0;
        }
    }

    return 1;
}
