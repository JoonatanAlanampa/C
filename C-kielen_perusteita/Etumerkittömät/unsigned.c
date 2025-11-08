#include <stdio.h>
#include <limits.h>
#include "unsigned.h"

void ucharIntervalli(unsigned char sade, unsigned char askel)
{

    int lippu=1, juuriliputettu=1;
    unsigned char arvo=UCHAR_MAX-sade+1, tilapainen1, tilapainen2;
    printf("unsigned char: ");

    for(;;)
    {
        if(lippu==1 || arvo+askel<=sade)
        {
            printf("%u ", arvo);
        }
        tilapainen1=arvo;
        tilapainen2=arvo+askel;
        if(tilapainen1>tilapainen2)
        {
            if(lippu==0)
            {
                printf("%u\n", arvo);
                break;
            }
            lippu=0;
            arvo+=askel;
            juuriliputettu=0;
        }
        if(lippu==0 && arvo+askel>sade)
        {
            printf("%u\n", arvo);
            break;
        }
        if(juuriliputettu==0)
        {
            juuriliputettu=1;
            arvo-=askel;
        }
        arvo+=askel;
    }

}


void ushortIntervalli(unsigned short sade, unsigned short askel)
{
    int lippu=1;
    unsigned short arvo=USHRT_MAX-sade+1, tilapainen1, tilapainen2;
    printf("unsigned short: ");

    for(;;)
    {
        tilapainen1=arvo;
        tilapainen2=arvo+askel;
        if(lippu==0 && arvo+askel>sade)
        {
            printf("%u\n", arvo);
            break;
        }
        if(lippu==1&&tilapainen2>sade&&tilapainen1>tilapainen2)
        {
            printf("%u\n", arvo);
            break;
        }
        if(tilapainen2<=sade && lippu==0)
        {
            if(arvo+askel>sade)
            {
                ;
            }
            else
            {

                printf("%u ", arvo);
            }
        }
        if(lippu==1)
        {
            printf("%u ", arvo);
        }
        if(tilapainen1>tilapainen2)
        {
            if(tilapainen2>sade)
            {
                printf("%u\n", arvo);
                break;
            }
            lippu=0;
        }
        arvo+=askel;
    }
}

void uintIntervalli(unsigned int sade, unsigned int askel)
{
    int lippu=1, juuriliputettu=1;
    unsigned int arvo=UINT_MAX-sade+1, tilapainen1, tilapainen2;
    printf("unsigned int: ");

    for(;;)
    {
        tilapainen1=arvo;
        tilapainen2=arvo+askel;
        if(tilapainen1>tilapainen2)
        {
            if(lippu==0)
            {
                printf("%u\n", arvo);
                break;
            }
            lippu=0;
            arvo+=askel;
            juuriliputettu=0;
        }
        if(juuriliputettu==0)
        {
            juuriliputettu=1;
            arvo-=askel;
        }
        if(lippu==1 || arvo+askel<=sade)
        {
            printf("%u ", arvo);
        }
        if(lippu==0 && arvo+askel>sade)
        {
            printf("%u\n", arvo);
            break;
        }
        arvo+=askel;
    }

}

void ulongIntervalli(unsigned long sade, unsigned long askel)
{
    int lippu=1, juuriliputettu=1;
    unsigned long arvo=ULONG_MAX-sade+1, tilapainen1, tilapainen2;
    printf("unsigned long: ");

    for(;;)
    {
        tilapainen1=arvo;
        tilapainen2=arvo+askel;
        if(tilapainen1>tilapainen2)
        {
            if(lippu==0)
            {
                printf("%lu\n", arvo);
                break;
            }
            lippu=0;
            arvo+=askel;
            juuriliputettu=0;
        }
        if(juuriliputettu==0)
        {
            juuriliputettu=1;
            arvo-=askel;
        }
        if(lippu==1 || arvo+askel<=sade)
        {
            printf("%lu ", arvo);
        }
        if(lippu==0 && arvo+askel>sade)
        {
            printf("%lu\n", arvo);
            break;
        }
        arvo+=askel;
    }

}
