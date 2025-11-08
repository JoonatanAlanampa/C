#include "vaihto.h"

void vaihda(int *a, int *b)
{
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void jarjesta(int *a, int *b, int *c)
{
    if(*a>*b)
    {
        vaihda(a, b);
    }
    if(*b>*c)
    {
        vaihda(b, c);
    }
    if(*a>*b)
    {
        vaihda(a, b);
    }
}
