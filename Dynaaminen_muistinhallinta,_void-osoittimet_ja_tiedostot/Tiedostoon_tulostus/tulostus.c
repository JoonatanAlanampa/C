#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tulostus.h"

void tulostaDblTaulu(double *taulu, size_t lkm, const char *taulNimi, int tarkkuus, const char *tiedNimi)
{
    FILE *td = fopen(tiedNimi, "w");
    size_t i;

    for(i=0; i<lkm; i++)
    {
        fprintf(td, "%s[%ld] = %.*f\n", taulNimi, i, tarkkuus, taulu[i]);
    }
    fclose(td);
}
