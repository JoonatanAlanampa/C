#include <stdio.h>
#include <stdlib.h>
#include "muunto.h"

int main(int argc, char *argv[])
{
    int ii;
    for(ii=1; ii<argc; ii++)
    {
        printf("%d: %s --> ", ii, argv[ii]);
        muunna(argv[ii]);
        printf("%s\n", argv[ii]);
    }
    return 0;
}
