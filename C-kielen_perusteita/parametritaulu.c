#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, i2, leveys1=0, leveys2=0, suurin=argc-1;

    for(;;)
    {
        suurin/=10;
        leveys1++;
        if(suurin==0)
        {
            break;
        }
    }

    for(i=1; i<argc; i++)
    {
        if(strlen(argv[i])>leveys2)
        {
            leveys2=strlen(argv[i]);
        }
    }

    for(i=0; i<leveys1+leveys2+4+2+1; i++)
    {
        printf("#");
    }

    printf("\n");

    for(i=1; i<argc; i++)
    {
        printf("# %*d | %-*s #\n", leveys1, i, leveys2, argv[i]);

        if(i!=argc-1)
        {


        for(i2=0; i2<leveys1+leveys2+4+2+1; i2++)
        {
            if(i2==0)
            {
                printf("#");
            }
            else if(i2==leveys1+leveys2+4+2)
            {
                printf("#\n");
            }
            else if(i2==leveys1+3)
            {
                printf("+");
            }
            else
            {
                printf("-");
            }
        }
        }
    }

    for(i=0; i<leveys1+leveys2+4+2+1; i++)
    {
        printf("#");
    }

    printf("\n");

    return 0;
}
