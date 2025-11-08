#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pituus;
    int i = 1;
    while(i<argc)
    {
        pituus = (unsigned int)strlen(argv[i]);
        printf("%d: %s (pituus: %u)\n", i, argv[i], pituus);
        i++;
    }

    return 0;
}
