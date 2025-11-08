#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, counter = 0, leveys;

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);

    int suurin = b*d;
    int rivimaara = b-a;
    int rivilaskuri = a-1;
    int sarakemaara = d-c;
    int sarakelaskuri = c-1;

    for(;;)
    {
        suurin/=10;
        counter++;
        if(suurin==0)
        {
            break;
        }
    }

    leveys=counter+1;

    for(i=0; i<=(sarakemaara+1)*(rivimaara+1)+sarakemaara+rivimaara+2; i++)
    {
        if(rivilaskuri==a-1 && sarakelaskuri==c-1)
        {
            printf("%*s", leveys, "");
        }
        else if(rivilaskuri!=a-1 && sarakelaskuri==c-1 && rivilaskuri!=b)
        {
            printf("%*d", leveys, rivilaskuri);
        }
        else if(rivilaskuri==b && sarakelaskuri==c-1)
        {
            printf("%*d\n", leveys, rivilaskuri);
        }
        else if(rivilaskuri==a-1 && sarakelaskuri!=c-1)
        {
            printf("%*d", leveys, sarakelaskuri);
        }
        else if(rivilaskuri==b && sarakelaskuri!=c-1)
        {
            printf("%*d\n", leveys, sarakelaskuri*rivilaskuri);
        }
        else
        {
            printf("%*d", leveys, sarakelaskuri*rivilaskuri);
        }
        rivilaskuri++;
        if(rivilaskuri==b+1)
        {
            rivilaskuri=a-1;
            sarakelaskuri++;
        }
    }

    return 0;
}
