#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int i, eksponentti=0, painoarvo, etumerkiton=0, etumerkki;
    double arvoosa=0, liukuluku;

    for(i=9; i<32; i++)
    {
        painoarvo=i-8;
         if(argv[1][i] == '1')
         {
             arvoosa+=pow(0.5, painoarvo);
         }
    }

    arvoosa+=1;

    printf("%.15f\n", arvoosa);

    for(i=1; i<9; i++)
    {
        if(argv[1][i] == '1')
         {
             etumerkiton+=pow(2, 9-i-1);
         }
    }

    eksponentti=etumerkiton-127;

    printf("%d\n", eksponentti);

    if(argv[1][0]=='1')
    {
        etumerkki=-1;
        printf("-\n");
    }
    else
    {
        etumerkki=1;
        printf("+\n");
    }

    liukuluku=arvoosa*pow(2, eksponentti)*etumerkki;

    printf("%.15f\n", liukuluku);

    return 0;
}
