#include <stddef.h>
#include "genhaku.h"

size_t etsi(void *mista, size_t n, void *mita, size_t m, size_t koko)
{
    char *a = mista, *b = mita;
    size_t i, j, k;
    int lippu=1;

    for(i=0; i<n; i++)
    {
        lippu=1;
        for(j=0; j<m; j++)
        {
            for(k=0; k<koko; k++)
            {
                if(a[(i+j)*koko + k] != b[j*koko + k])
                {
                    lippu=0;
                }
            }
        }
        if(lippu)
        {
            return i;
        }
    }

    return n;
}
