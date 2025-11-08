#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, i2, counter=0, nro;
    int *voittorivi = malloc(7*sizeof(int));
    int *lottorivi = malloc(7*sizeof(int));
    int *osumat = malloc(7*sizeof(int));

    for(i=0; i<7; i++)
    {
        voittorivi[i] = atoi(argv[i+1]);
        lottorivi[i] = atoi(argv[i+8]);
    }

    printf("Voittorivi: ");

    for(i=0; i<7; i++)
    {
        if(i==6)
        {
           printf("%d", voittorivi[i]);
           break;
        }
        printf("%d ", voittorivi[i]);
    }

    printf("\n");
    printf("Lottorivi: ");

    for(i=0; i<7; i++)
    {
        if(i==6)
        {
           printf("%d", lottorivi[i]);
           break;
        }
        printf("%d ", lottorivi[i]);
    }

    printf("\n");

    for(i=0; i<7; i++)
    {
        nro = lottorivi[i];
        for(i2=0; i2<7; i2++)
        {
            if(nro==voittorivi[i2])
            {
                osumat[counter]=voittorivi[i2];
                counter++;
                break;
            }
        }
    }

    if(counter>0)
    {
        printf("%d oikein: ", counter);
        for(i=0; i<counter; i++)
        {
            if(counter-i-1==0)
            {
                printf("%d", osumat[i]);
                break;
            }
            printf("%d ", osumat[i]);
        }
    }
    else
    {
        printf("Ei yhtään oikein!");
    }

    printf("\n");

    free(voittorivi);
    free(lottorivi);
    free(osumat);
    return 0;
}
