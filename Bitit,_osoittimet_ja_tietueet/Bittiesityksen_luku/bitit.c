#include <stdio.h>
#include <limits.h>
#include "bitit.h"

/*void scharBitit(signed char x);
void shortBitit(short int x);
void intBitit(int x);
void longBitit(long int x);

int main()
{
    scharBitit(2015);
    shortBitit(2015);
    intBitit(2015);
    longBitit(2015);
    return 0;
}*/

void scharBitit(signed char x)
{
    int i, nollalaskuri=0, ykkoslaskuri=0;

    printf("%d\n", x);

    for(i=CHAR_BIT*sizeof(signed char)-1; i>=0; i--)
    {
         if((x >> i) & 1)
         {
             printf("1");
            ykkoslaskuri++;
         }
         else
         {
             printf("0");
             nollalaskuri++;
         }
    }

    printf("\n");

    printf("%d\n", nollalaskuri);

    printf("%d\n", ykkoslaskuri);

}

void shortBitit(short int x)
{
    int i, nollalaskuri=0, ykkoslaskuri=0;

    printf("%d\n", x);

    for(i=CHAR_BIT*sizeof(short int)-1; i>=0; i--)
    {
         if((x >> i) & 1)
         {
             printf("1");
            ykkoslaskuri++;
         }
         else
         {
             printf("0");
             nollalaskuri++;
         }
    }

    printf("\n");

    printf("%d\n", nollalaskuri);

    printf("%d\n", ykkoslaskuri);
}

void intBitit(int x)
{
    int i, nollalaskuri=0, ykkoslaskuri=0;

    printf("%d\n", x);

    for(i=CHAR_BIT*sizeof(int)-1; i>=0; i--)
    {
         if((x >> i) & 1)
         {
             printf("1");
            ykkoslaskuri++;
         }
         else
         {
             printf("0");
             nollalaskuri++;
         }
    }

    printf("\n");

    printf("%d\n", nollalaskuri);

    printf("%d\n", ykkoslaskuri);
}

void longBitit(long int x)
{
    long int i, nollalaskuri=0, ykkoslaskuri=0;

    printf("%ld\n", x);

    for(i=CHAR_BIT*sizeof(long int)-1; i>=0; i--)
    {
         if((x >> i) & 1)
         {
             printf("1");
            ykkoslaskuri++;
         }
         else
         {
             printf("0");
             nollalaskuri++;
         }
    }

    printf("\n");

    printf("%ld\n", nollalaskuri);

    printf("%ld\n", ykkoslaskuri);

}
