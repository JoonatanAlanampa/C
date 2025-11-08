#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "muunto.h"

void muunna(char mj[])
{
    int i, j, pituus=strlen(mj);
    char temp;
    for(i=0; i<pituus; i++)
    {
        if(isupper(mj[i]))
        {
            mj[i]=tolower(mj[i]);
        }
        else
        {
            mj[i]=toupper(mj[i]);
        }
    }

    j=pituus-1;

    for(i=0; i<j; i++)
    {
        temp=mj[i];
        mj[i] = mj[j];
        mj[j] = temp;

        j--;
    }
}
