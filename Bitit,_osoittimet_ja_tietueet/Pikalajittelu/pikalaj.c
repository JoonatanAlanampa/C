#include "pikalaj.h"
#include "kolmijako.h"

void pikalajittele(int alku, int loppu, int t[])
{
    int a, b, x, y;
    IntPari pari;

    unsigned int koko;

    if(alku>=loppu)
    {
        return;
    }

    a=alku;
    b=loppu;
    koko=b-a+1;

    pari = kolmijako(koko, t+alku, a-alku, b-alku, &x, &y);

    pikalajittele(alku, alku+pari.x-1, t);
    pikalajittele(alku+pari.x+1, alku+pari.y-1, t);
    pikalajittele(alku+pari.y+1, loppu, t);

}
