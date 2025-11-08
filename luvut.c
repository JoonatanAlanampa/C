#include <stdio.h>

main()
{
    int i = 1;
    while(i<=100)
    {
        if(i%2!=0 && i%3!=0 && i%5!=0)
        {
            if(i==97)
            {
                printf("%d", i);
            }
            else
            {
                printf("%d ", i);
            }
        }
        i++;
    }
    printf("\n");
    return 0;
}
