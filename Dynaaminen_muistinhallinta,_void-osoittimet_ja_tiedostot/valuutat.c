#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Valuutta
{
    char valuutta[4];
    double kurssi;
};

typedef struct Valuutta Valuutta;

int cmp(const void *a, const void *b)
{
    Valuutta *val1 = (Valuutta *)a;
    Valuutta *val2 = (Valuutta *)b;
    return strcmp(val1->valuutta, val2->valuutta);
}

int main()
{
    int i, pituus=0, kap=1, lippu=1;

    char valuutta[4];

    double kurssi, rahamaara;

    Valuutta *valuutat = malloc(kap*sizeof(Valuutta));

    char rivi[80];

    char komento[10];

    while(fgets(rivi, 100, stdin))
    {
        lippu=1;
        if (sscanf(rivi, "%s", komento) == 1)
        {
            if (strcmp(komento, "lopeta") == 0)
            {
                break;
            }
        }
        if (sscanf(rivi, "%s%s%lf", komento, valuutta, &kurssi) == 3)
        {
            if (strcmp(komento, "kurssi") == 0)
            {
                for(i=0; i<pituus; i++)
                {
                    if (strcmp(valuutat[i].valuutta, valuutta) == 0)
                    {
                        valuutat[i].kurssi = kurssi;
                        lippu = 0;
                        break;
                    }
                }

                if(lippu==1)
                {
                    if (pituus == kap)
                    {
                        kap *= 2;
                        valuutat = realloc(valuutat, kap*sizeof(Valuutta));
                    }

                    strncpy(valuutat[pituus].valuutta, valuutta, 3);
                    valuutat[pituus].valuutta[3] = '\0';
                    valuutat[pituus].kurssi = kurssi;
                    pituus++;
                }
            }
        }
        if(sscanf(rivi, "%s%lf%s", komento, &rahamaara, valuutta)==3)
        {
            if (strcmp(komento, "muunna") == 0)
            {
                for(i=0; i<pituus; i++)
                {
                    if (strcmp(valuutat[i].valuutta, valuutta) == 0)
                    {
                        printf("%.3f %s = %.3f EUR\n", rahamaara, valuutta, rahamaara/valuutat[i].kurssi);
                        lippu=0;
                        break;
                    }
                }
                if(lippu==1)
                {
                    printf("Valuutan %s kurssia ei ole tiedossa!\n", valuutta);
                }
            }
        }
        if(sscanf(rivi, "%s", komento)==1)
        {
            if(strcmp(komento, "kurssit")==0)
            {
                qsort(valuutat, pituus, sizeof(Valuutta), cmp);
                for(i=0; i<pituus; i++)
                {
                    printf("%s %.3f\n", valuutat[i].valuutta, valuutat[i].kurssi);
                }
            }
        }
    }

    free(valuutat);
    return 0;
}
