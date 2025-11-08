#include <stdio.h>
#include <math.h>
#include "murtoluku.h"

Murtoluku supistettuML(int os, int nim)
{
    int tmp1, tmp2, pieni, iso, syt;
    Murtoluku murtoluku;
    murtoluku.os = os;
    murtoluku.nim = nim;

    if(os==0 || nim==0)
    {
        return murtoluku;
    }
    if(nim<0)
    {
        os*=-1;
        nim*=-1;
    }
    tmp1 = fabs(os);
    tmp2 = fabs(nim);

    if(tmp1<tmp2)
    {
        pieni=tmp1;
        iso=tmp2;
    }
    else
    {
        pieni=tmp2;
        iso=tmp1;
    }
    while(pieni!=iso)
    {
        if(iso<pieni)
        {
            tmp1=pieni;
            pieni=iso;
            iso=tmp1;
        }
        iso-=pieni;
    }

    syt = iso;

    os/=syt;
    nim/=syt;

    murtoluku.os = os;
    murtoluku.nim = nim;

    return murtoluku;
}

Murtoluku lisaaML(Murtoluku a, Murtoluku b)
{
    int os_summa = a.os*b.nim+a.nim*b.os, nim_summa = a.nim*b.nim;

    return supistettuML(os_summa, nim_summa);
}

Murtoluku vahennaML(Murtoluku a, Murtoluku b)
{
    int os_erotus = a.os*b.nim-a.nim*b.os, nim_erotus = a.nim*b.nim;

    return supistettuML(os_erotus, nim_erotus);
}

Murtoluku kerroML(Murtoluku a, Murtoluku b)
{
    int os_tulo = a.os*b.os, nim_tulo = a.nim*b.nim;

    return supistettuML(os_tulo, nim_tulo);
}

Murtoluku jaaML(Murtoluku a, Murtoluku b)
{
    int os_osamaara = a.os*b.nim, nim_osamaara = a.nim*b.os;

    return supistettuML(os_osamaara, nim_osamaara);
}

void tulostaML(Murtoluku ml)
{
    if(ml.os==0)
    {
        printf("0");
    }
    else if(ml.nim==1)
    {
        printf("%d", ml.os);
    }
    else
    {
        printf("%d/%d", ml.os, ml.nim);
    }
}
