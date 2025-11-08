#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "kortit.h"

const char *MAIDEN_NIMET[MAA_LKM + 1] = {"", "Hertta", "Ruutu", "Risti", "Pata"};

const char *KORTTIEN_NIMET[MAA_KOKO + 1] = {"", "ässä", "kakkonen", "kolmonen", "nelonen",
"viitonen", "kuutonen", "seiska", "kasi", "ysi", "kymppi", "jätkä", "rouva", "kunkku"};

void tulostaKortti(Kortti kortti)
{
    int i, j, k, h, pituus1, pituus2;
    for(i=1; i<=MAA_LKM; i++)
    {
        if(MAIDEN_NIMET[kortti.maa]==MAIDEN_NIMET[i])
        {
            for(j=1; j<=MAA_KOKO; j++)
            {
                if(KORTTIEN_NIMET[kortti.arvo]==KORTTIEN_NIMET[j])
                {
                    pituus1 = strlen(MAIDEN_NIMET[i]);
                    for(k=0; k<pituus1; k++)
                    {
                        if(k==0)
                        {
                            printf("%c", toupper(MAIDEN_NIMET[i][k]));
                        }
                        else
                        {
                            printf("%c", MAIDEN_NIMET[i][k]);
                        }
                    }
                    pituus2 = strlen(KORTTIEN_NIMET[j]);
                    for(h=0; h<pituus2; h++)
                    {
                        printf("%c", KORTTIEN_NIMET[j][h]);
                    }
                }
            }
        }
    }
}

void tulostaKorttiOs(const Kortti *korttiOs)
{
    int i, j, k, h, pituus1, pituus2;
    for(i=1; i<=MAA_LKM; i++)
    {
        if(MAIDEN_NIMET[korttiOs->maa]==MAIDEN_NIMET[i])
        {
            for(j=1; j<=MAA_KOKO; j++)
            {
                if(KORTTIEN_NIMET[korttiOs->arvo]==KORTTIEN_NIMET[j])
                {
                    pituus1 = strlen(MAIDEN_NIMET[i]);
                    for(k=0; k<pituus1; k++)
                    {
                        if(k==0)
                        {
                            printf("%c", toupper(MAIDEN_NIMET[i][k]));
                        }
                        else
                        {
                            printf("%c", MAIDEN_NIMET[i][k]);
                        }
                    }
                    pituus2 = strlen(KORTTIEN_NIMET[j]);
                    for(h=0; h<pituus2; h++)
                    {
                        printf("%c", KORTTIEN_NIMET[j][h]);
                    }
                }
            }
        }
    }
}
