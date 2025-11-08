#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "caesar.h"

void caesarKoodaa(char mj[], char aakkosto[], char korvaavat[])
{
    int i;
    int pituus = strlen(aakkosto);
    char korvaus[UCHAR_MAX+1];

    for(i=0; i < UCHAR_MAX+1; i++)
    {
        korvaus[i]=i;
    }

    for(i=0; i<pituus; i++)
    {
        korvaus[(unsigned char) aakkosto[i]] = korvaavat[i];
    }

    for(i=0; mj[i] != '\0'; i++)
    {
        mj[i] = korvaus[(unsigned char) mj[i]];
    }
}
