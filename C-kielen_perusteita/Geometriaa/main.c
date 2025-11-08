#include <stdio.h>
#include <stdlib.h>
#include "geometria.h"

int main(int argc, char *argv[])
{
    int i;

    double sade;

    printf("Piin arvo: %.19Lf\n", PII);

    for(i=1; i<argc; i++)
    {
        sade = atof(argv[i]);
        printf("Säteen %f omaavan ympyrän ala ja pallon tilavuus: %.10f ja %.10f\n", sade, ympyranAla(sade), pallonTilavuus(sade));
        printf("Säteen %f omaavan ympyrän piiri on %.10Lf\n", sade, 2*PII*sade);
    }

    return 0;
}
