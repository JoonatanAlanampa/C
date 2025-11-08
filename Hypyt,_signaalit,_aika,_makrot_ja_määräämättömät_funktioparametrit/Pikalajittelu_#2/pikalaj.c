#include <stdio.h>
#include "pikalaj.h"
#include "kolmijako.h"

static int ypituus = 0;

static void pikalajitteleRek(int alku, int loppu, int t[]);

void pikalajittele(int alku, int loppu, int t[])
{
    pikalajitteleRek(alku, loppu, t);

    #ifdef KOLMIJAON_TYO
        printf("Kolmijaon kokonaistyö: %d\n", ypituus);
    #endif
}

static void pikalajitteleRek(int alku, int loppu, int t[])
{
    int a, b, x, y;
    unsigned int koko;
    IntPari pari;

    if(alku>=loppu)
    {
        return;
    }

    a=alku;
    b=loppu;
    koko=b-a+1;

    ypituus+=koko;

    #ifdef KOLMIJAON_RAJAT
        printf("Kolmijako %d %d\n", a, b);
    #endif

    pari = kolmijako(koko, t+alku, a-alku, b-alku, &x, &y);

    pikalajitteleRek(alku, alku+pari.x-1, t);
    pikalajitteleRek(alku+pari.x+1, alku+pari.y-1, t);
    pikalajitteleRek(alku+pari.y+1, loppu, t);

}
