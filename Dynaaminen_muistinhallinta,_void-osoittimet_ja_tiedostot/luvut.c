#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int vrt(const void *a, const void *b)
{
    double diff = *(double *)a - *(double *)b;
    if (diff < 0) return -1;
    else if (diff > 0) return 1;
    else return 0;
}

int main()
{
    size_t i, koko = 2, pituus=0;

    double *t = malloc(koko*sizeof(double));

    double syote, summa=0, keskiarvo;

    while(scanf("%lf", &syote)==1)
    {
        if(pituus==koko)
        {
            koko = 2*koko;
            t=realloc(t, koko*sizeof(double));
        }
        t[pituus]=syote;
        pituus++;
    }

    t=realloc(t, pituus*sizeof(double));

    qsort(t, pituus, sizeof(double), vrt);

    printf("Luettiin %lu lukua: ", pituus);

    for(i=0; i<pituus; i++)
    {
        if(i+1==pituus)
        {
            printf("%.3f\n", t[i]);
        }
        else
        {
            printf("%.3f ", t[i]);
        }
        summa+=t[i];
    }

    printf("Summa: %.3f\n", summa);

    if(pituus>0)
    {
        keskiarvo = summa/pituus;

        printf("Keskiarvo: %.3f\n", keskiarvo);
    }

    free(t);

    return 0;
}
