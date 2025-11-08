#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "yhdista.h"

char *yhdista(const char *mj, ...)
{
    int pituus = strlen(mj);

    const char *tmp = mj;

    char *umj;

    va_list pl;

    va_start(pl, mj);

    while((tmp = va_arg(pl, const char *)) != NULL)
    {
        pituus += strlen(tmp);
    }

    va_end(pl);

    umj = malloc(pituus+1);

    strcpy(umj, mj);

    va_start(pl, mj);

    while((tmp = va_arg(pl, const char *)) != NULL)
    {
        strcat(umj, tmp);
    }

    va_end(pl);

    return umj;
}
