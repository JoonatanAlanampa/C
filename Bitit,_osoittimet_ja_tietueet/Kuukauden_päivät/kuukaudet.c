#include <ctype.h>
#include <string.h>
#include "kuukaudet.h"

const char *KK_NIMET[KK_LKM] = {"tammikuu", "helmikuu", "maaliskuu", "huhtikuu", "toukokuu", "kesäkuu", "heinäkuu",
"elokuu", "syyskuu", "lokakuu", "marraskuu", "joulukuu"};

const char KK_PAIVAT[2][KK_LKM] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };

int karkausvuosi(int vuosiluku)
{
    if(vuosiluku%4==0 && vuosiluku%100!=0)
    {
        return 1;
    }
    else if(vuosiluku%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char kkPituus(const char *kkNimi, int vuosiluku)
{
    int i, i2, pituus=strlen(kkNimi)/*, kuukausi_indeksi=100*/;

    for(i=0; i<KK_LKM; i++)
    {
        for(i2=0; i2<pituus; i2++)
        {
            if(tolower(kkNimi[i2])!=KK_NIMET[i][i2])
            {
                break;
            }
            if(i2==pituus-1 && tolower(kkNimi[pituus-1])==KK_NIMET[i][pituus-1])
            {
                return KK_PAIVAT[karkausvuosi(vuosiluku)][i];
                /*kuukausi_indeksi=i;*/
            }
        }
    }

    return -1;

    /*if(kuukausi_indeksi==100)
    {
        return -1;
    }

    if(karkausvuosi(vuosiluku)==1)
    {
        return KK_PAIVAT[1][kkNimi];
    }
    else
    {
        return KK_PAIVAT[0][kkNimi];
    }*/
}
