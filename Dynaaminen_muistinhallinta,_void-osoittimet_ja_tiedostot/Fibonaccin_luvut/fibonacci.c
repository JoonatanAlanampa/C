#include <stdlib.h>
#include "fibonacci.h"

unsigned int * fib_jono(unsigned int n)
{
    int i, alku1=0, alku2=1, summa;
    unsigned int *fib = malloc(n*sizeof(unsigned int));

    if (fib == NULL)
    {
        return NULL;
    }

    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            fib[i]=alku1;
        }
        else if(i==1)
        {
            fib[i]=alku2;
        }
        else
        {
            summa=alku1+alku2;
            fib[i]=summa;
            alku1=alku2;
            alku2=summa;
        }
    }

    return fib;
}
