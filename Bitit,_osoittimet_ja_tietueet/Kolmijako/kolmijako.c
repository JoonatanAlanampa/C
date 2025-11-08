#include "kolmijako.h"

IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2, int *p1, int *p2)
{
    int i, tmp, pienet1=0, pienet2;
    IntPari pari;

    if(t[vipu1] > t[vipu2])
    {
        tmp=t[vipu1];
        t[vipu1]=t[vipu2];
        t[vipu2]=tmp;
    }

    for(i=0; i<n; i++)
    {
        if(t[i]<t[vipu1])
        {
            tmp=t[i];
            t[i]=t[pienet1];
            t[pienet1]=tmp;
            if(vipu1 == pienet1)
            {
                vipu1=i;
            }
            else if(vipu2 == pienet1)
            {
                vipu2=i;
            }
            pienet1++;
        }
    }

    tmp=t[vipu1];
    t[vipu1]=t[pienet1];
    t[pienet1]=tmp;

    if (vipu2 == pienet1)
    {
        vipu2=vipu1;
    }

    pienet2=pienet1+1;

    for(i=pienet2; i<n; i++)
    {
        if(t[i]<t[vipu2])
        {
            tmp=t[i];
            t[i]=t[pienet2];
            t[pienet2]=tmp;
            if(vipu2 == pienet2)
            {
                vipu2=i;
            }
            pienet2++;
        }
    }

    tmp=t[vipu2];
    t[vipu2]=t[pienet2];
    t[pienet2]=tmp;

    *p1 = pienet1;
    *p2 = pienet2;

    pari.x = pienet1;
    pari.y = pienet2;

    return pari;
}
