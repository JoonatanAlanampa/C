#include <stdio.h>
#include <string.h>
#include "pvm.h"

Pvm * kasvataPvm(Pvm *pvm)
{

    if(pvm->vuosi%4==0 && pvm->vuosi%100!=0)
    {
        if(pvm->kk == 4 || pvm->kk == 6 || pvm->kk == 9 || pvm->kk == 11)
        {
            if(pvm->pv==30)
            {
                pvm->pv=1;
                pvm->kk++;
            }
            else
            {
                pvm->pv++;
            }
        }
        else if(pvm->kk==2)
        {
            if(pvm->pv==29)
            {
                pvm->pv=1;
                pvm->kk++;
            }
            else
            {
                pvm->pv++;
            }
        }
        else
        {
            if(pvm->pv==31)
            {
                pvm->pv=1;
                pvm->kk++;
                if(pvm->kk==13)
                {
                    pvm->vuosi++;
                    pvm->kk=1;
                }
            }
            else
            {
                pvm->pv++;
            }
        }
    }
    else if(pvm->vuosi%400==0)
    {
        if(pvm->kk == 4 || pvm->kk == 6 || pvm->kk == 9 || pvm->kk == 11)
        {
            if(pvm->pv==30)
            {
                pvm->pv=1;
                pvm->kk++;
            }
            else
            {
                pvm->pv++;
            }
        }
        else if(pvm->kk==2)
        {
            if(pvm->pv==29)
            {
                pvm->pv=1;
                pvm->kk++;
            }
            else
            {
                pvm->pv++;
            }
        }
        else
        {
            if(pvm->pv==31)
            {
                pvm->pv=1;
                pvm->kk++;
                if(pvm->kk==13)
                {
                    pvm->vuosi++;
                    pvm->kk=1;
                }
            }
            else
            {
                pvm->pv++;
            }
        }
    }
    else
    {
        if(pvm->kk == 4 || pvm->kk == 6 || pvm->kk == 9 || pvm->kk == 11)
        {
            if(pvm->pv==30)
            {
                pvm->pv=1;
                pvm->kk++;
            }
            else
            {
                pvm->pv++;
            }
        }
        else if(pvm->kk==2)
        {
            if(pvm->pv==28)
            {
                pvm->pv=1;
                pvm->kk++;
            }
            else
            {
                pvm->pv++;
            }
        }
        else
        {
            if(pvm->pv==31)
            {
                pvm->pv=1;
                pvm->kk++;
                if(pvm->kk==13)
                {
                    pvm->vuosi++;
                    pvm->kk=1;
                }
            }
            else
            {
                pvm->pv++;
            }
        }
    }
    if(strcmp(pvm->vk_pv, "ma")==0)
    {
        strcpy(pvm->vk_pv, "ti");
    }
    else if(strcmp(pvm->vk_pv, "ti")==0)
    {
        strcpy(pvm->vk_pv, "ke");
    }
    else if(strcmp(pvm->vk_pv, "ke")==0)
    {
        strcpy(pvm->vk_pv, "to");
    }
    else if(strcmp(pvm->vk_pv, "to")==0)
    {
        strcpy(pvm->vk_pv, "pe");
    }
    else if(strcmp(pvm->vk_pv, "pe")==0)
    {
        strcpy(pvm->vk_pv, "la");
    }
    else if(strcmp(pvm->vk_pv, "la")==0)
    {
        strcpy(pvm->vk_pv, "su");
    }
    else if(strcmp(pvm->vk_pv, "su")==0)
    {
        strcpy(pvm->vk_pv, "ma");
    }

    return pvm;

}

unsigned int pvmEro(const Pvm *a, const Pvm *b)
{
    Pvm tmp1, tmp2;
    unsigned int ero=0;

    if(a->vuosi < b->vuosi)
    {
        tmp1=*a;
        tmp2=*b;
    }
    else if(a->vuosi==b->vuosi)
    {
        if(a->kk < b->kk)
        {
            tmp1=*a;
            tmp2=*b;
        }
        else if(a->kk==b->kk)
        {
            if(a->pv < b->pv)
            {
                tmp1=*a;
                tmp2=*b;
            }
            else if(a->pv==b->pv)
            {
                return ero;
            }
            else
            {
                tmp1=*b;
                tmp2=*a;
            }
        }
        else
        {
            tmp1=*b;
            tmp2=*a;
        }
    }
    else
    {
        tmp1=*b;
        tmp2=*a;
    }

    while(tmp1.pv != tmp2.pv || tmp1.kk != tmp2.kk || tmp1.vuosi != tmp2.vuosi)
    {
        kasvataPvm(&tmp1);
        ero++;
    }

    return ero;
}

void tulostaPvm(Pvm *pvm)
{
    printf("%s %d.%d.%d", pvm->vk_pv, pvm->pv, pvm->kk, pvm->vuosi);
}
