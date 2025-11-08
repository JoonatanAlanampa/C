#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(int argc, char *argv[])
{
    int i, i2, kpllaskuri=1, maxlaskuri=1, uniikkilaskuri=0, uniikkilippu=1, maxkpl=1;
    double pienin=DBL_MAX, suurin=-DBL_MAX, arvo;

    for(i=1; i<argc; i++)
    {
        arvo = atof(argv[i]);
        if(arvo<pienin)
        {
            pienin=arvo;
        }

        if(arvo>suurin)
        {
            suurin=arvo;
        }
    }

    printf("Pienin: %f\n", pienin);
    printf("Suurin: %f\n", suurin);

    for(i=1; i<argc; i++)
    {
        arvo = atof(argv[i]);
        kpllaskuri=1;
        for(i2=1; i2<argc; i2++)
        {
            if(i!=i2 && arvo==atof(argv[i2]))
            {
                kpllaskuri++;
            }
        }
        if(kpllaskuri==1)
        {
            uniikkilaskuri++;
        }
        kpllaskuri=1;
    }

    if(uniikkilaskuri>0)
    {
        printf("Ainutlaatuiset: ");

        for(i=1; i<argc; i++)
        {
            arvo = atof(argv[i]);
            kpllaskuri=1;
            for(i2=1; i2<argc; i2++)
            {
                if(i!=i2 && arvo==atof(argv[i2]))
                {
                    kpllaskuri++;
                }
            }
            if(kpllaskuri == 1)
            {
                uniikkilaskuri--;
                if(uniikkilaskuri==0)
                {
                    printf("%f\n", arvo);
                }
                else
                {
                    printf("%f ", arvo);
                }
            }
            kpllaskuri=1;
        }
    }

    for(i=1; i<argc; i++)
    {
        arvo = atof(argv[i]);
        for(i2=i+1; i2<argc; i2++)
        {
            if(arvo==atof(argv[i2]))
            {
                uniikkilippu=0;
                kpllaskuri++;
            }
            if(i2+1==argc)
            {
                if(kpllaskuri>=maxlaskuri)
                {
                    maxkpl++;
                }
                if(kpllaskuri>maxlaskuri)
                {
                    maxkpl=1;
                    maxlaskuri=kpllaskuri;
                }
                kpllaskuri=1;
                break;
            }
        }
    }

    if(uniikkilippu==0)
    {
        printf("Useimmiten esiintyneet (%d kertaa): ", maxlaskuri);
        for(i=1; i<argc; i++)
        {
            arvo = atof(argv[i]);
            for(i2=i+1; i2<argc; i2++)
            {
                if(arvo==atof(argv[i2]))
                {
                    kpllaskuri++;
                }
                if(i2+1==argc)
                {
                    if(kpllaskuri==maxlaskuri)
                    {
                        maxkpl--;
                        if(maxkpl==0)
                        {
                            printf("%f\n", arvo);
                        }
                        else
                        {
                            printf("%f ", arvo);
                        }
                    }
                    kpllaskuri=1;
                    break;
                }
            }
        }
    }

    return 0;
}
