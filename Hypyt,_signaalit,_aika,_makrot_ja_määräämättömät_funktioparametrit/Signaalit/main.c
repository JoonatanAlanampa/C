#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signaalit.h"

int main()
{
    char r[100];

    char komento[10];

    int a, b, lkm=0, arvo;

    unsigned int i, j;

    int *t = NULL;

    signal(SIGFPE, hoidaSIGFPE);
    signal(SIGSEGV, hoidaSIGSEGV);

    while(fgets(r, 100, stdin))
    {
        switch(setjmp(paluuTila))
        {
            case 0:
                if(sscanf(r, "%s%d%d", komento, &a, &b)==3)
                {
                    arvo=a/b;
                    lkm++;
                    t=realloc(t, lkm*sizeof(int));
                    t[lkm-1]=arvo;
                }
                else if(sscanf(r, "%s%u", komento, &i)==2 && strcmp(komento, "tulosta") == 0)
                {
                    printf("%d\n", t[i]);
                }
                else if(sscanf(r, "%s", komento)==1 && strcmp(komento, "tulosta") == 0)
                {
                    for(j=0; j<lkm; j++)
                    {
                        if(j+1==lkm)
                        {
                            printf("%d\n", t[j]);
                        }
                        else
                        {
                            printf("%d ", t[j]);
                        }
                    }
                }
                break;
            case SIGFPE:
                printf("Aiheutui signaali SIGFPE\n");
                break;
            case SIGSEGV:
                printf("Aiheutui signaali SIGSEGV\n");
                break;
            default:
                printf("Aiheutui signaali UNKNOWN\n");
                break;
        }
    }

    free(t);
    return 0;
}
