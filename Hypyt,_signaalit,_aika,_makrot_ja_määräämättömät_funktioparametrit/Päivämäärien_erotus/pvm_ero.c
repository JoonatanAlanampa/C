#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "pvm_ero.h"


void pvm_ero(const char *pvm1, const char *pvm2)
{
    int x, apv, akk, av, bpv, bkk, bv;
    double sec;
    char ta[20];
    char tb[20];

    struct tm apvm = {0};
    time_t a;
    struct tm bpvm = {0};
    time_t b;

    if(sscanf(pvm1, "%2d.%2d.%d", &apv, &akk, &av)==3)
    {
        if(apv>=0 && apv<=99 && akk>=0 && akk<=99)
        {
            ;
        }
        else
        {
            fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
            return;
        }
    }
    else
    {
        fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
        return ;
    }

    apvm.tm_mday = apv;
    apvm.tm_mon = akk-1;
    apvm.tm_year = av-1900;

    apvm.tm_isdst = 0;

    a = mktime(&apvm);

    if(apvm.tm_mday==apv && apvm.tm_mon == akk-1 && apvm.tm_year == av-1900)
    {
        ;
    }
    else
    {
        fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
        return;
    }

    if(sscanf(pvm2, "%2d.%2d.%d", &bpv, &bkk, &bv)==3)
    {
        if(bpv>=0 && bpv<=99 && bkk>=0 && bkk<=99)
        {
            ;
        }
        else
        {
            fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
            return;
        }
    }
    else
    {
        fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
        return;
    }

    bpvm.tm_mday = bpv;
    bpvm.tm_mon = bkk-1;
    bpvm.tm_year = bv-1900;

    bpvm.tm_isdst = 0;

    b = mktime(&bpvm);

    if(bpvm.tm_mday==bpv && bpvm.tm_mon == bkk-1 && bpvm.tm_year == bv-1900)
    {
        ;
    }
    else
    {
        fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
        return;
    }

    sec = difftime(a, b);

    x = (int)(sec / (60 * 60 * 24))+1;

    setlocale(LC_TIME, "fi_FI");
    strftime(ta, 20, "%A", &apvm);
    strftime(tb, 20, "%A", &bpvm);

    if(x<0)
    {
        sec = difftime(b, a);

        x = (sec / (60 * 60 * 24))+1;

        printf("%s %02d.%02d.%d --> %s %02d.%02d.%d: yhteensä %d päivää\n", ta, apv, akk, av, tb, bpv, bkk, bv, x);
    }
    else
    {
        printf("%s %02d.%02d.%d --> %s %02d.%02d.%d: yhteensä %d päivää\n", tb, bpv, bkk, bv, ta, apv, akk, av, x);
    }
}
