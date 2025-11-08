#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, b;

    if(argc!=3)
    {
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    if(a>b)
    {
        return 1;
    }

    for (; a <= b; a++)
    {
        printf("%d: %c\n", a, a);
    }

    return 0;
}
