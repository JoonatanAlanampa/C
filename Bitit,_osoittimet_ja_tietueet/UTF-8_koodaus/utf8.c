#include <limits.h>
#include "utf8.h"

void utf8_koodaa(unsigned int merkki, unsigned char utf8[])
{
    int i, lippu=1, laskuri=0, lyhin_koodaus;
    unsigned int x = merkki;

    for(i=0; i<CHAR_BIT*sizeof(unsigned int); i++)
    {
        if( (x >> i) & 1)
        {
            if(lippu==1)
            {
                lippu=0;
            }
            laskuri=i;
        }
    }



    lyhin_koodaus = laskuri+1;

    if(lyhin_koodaus<=7)
    {
        utf8[0]=0;
        utf8[1]='\0';
        utf8[0]=x;
    }
    else if(lyhin_koodaus<=11)
    {
        utf8[0]=0;
        utf8[1]=0;
        utf8[2]='\0';
        utf8[0] = utf8[0] | (1 << 7);
        utf8[0] = utf8[0] | (1 << 6);
        utf8[1] = utf8[1] | (1 << 7);
        utf8[0] = utf8[0] | ((x >> 6) & 0x1F);
        utf8[1] = utf8[1] | (x & 0x3F);
    }
    else if(lyhin_koodaus<=16)
    {
        utf8[0]=0;
        utf8[1]=0;
        utf8[2]=0;
        utf8[3]='\0';
        utf8[0] = utf8[0] | (1 << 7);
        utf8[0] = utf8[0] | (1 << 6);
        utf8[0] = utf8[0] | (1 << 5);
        utf8[1] = utf8[1] | (1 << 7);
        utf8[2] = utf8[2] | (1 << 7);
        utf8[0] = utf8[0] | ((x >> 12) & 0x0F);
        utf8[1] = utf8[1] | ((x >> 6) & 0x3F);
        utf8[2] = utf8[2] | (x & 0x3F);
    }
    else if(lyhin_koodaus<=21)
    {
        utf8[0]=0;
        utf8[1]=0;
        utf8[2]=0;
        utf8[3]=0;
        utf8[4]='\0';
        utf8[0] = utf8[0] | (1 << 7);
        utf8[0] = utf8[0] | (1 << 6);
        utf8[0] = utf8[0] | (1 << 5);
        utf8[0] = utf8[0] | (1 << 4);
        utf8[1] = utf8[1] | (1 << 7);
        utf8[2] = utf8[2] | (1 << 7);
        utf8[3] = utf8[3] | (1 << 7);
        utf8[0] = utf8[0] | ((x >> 18) & 0x07);
        utf8[1] = utf8[1] | ((x >> 12) & 0x3F);
        utf8[2] = utf8[2] | ((x >> 6) & 0x3F);
        utf8[3] = utf8[3] | (x & 0x3F);
    }


}
