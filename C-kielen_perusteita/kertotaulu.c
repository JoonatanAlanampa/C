#include <stdio.h>

main()
{
    char ch = 'x';
    int rivi = 0;
    int sarake = 0;
    int numerot = 0;

    while(numerot<=15*15+30)
    {
        if(rivi==0 && sarake==0)
        {
            printf("%4c", ch);
        }
        else if(rivi!=0 && sarake==0 && rivi!=15)
        {
            printf("%4d", rivi);
        }
        else if(sarake==0 && rivi==15)
        {
            printf("%4d\n", rivi);
        }
        else if(rivi==0 && sarake!=0)
        {
            printf("%4d", sarake);
        }
        else if(sarake!=0 && rivi==15)
        {
            printf("%4d\n", sarake*rivi);
        }
        else
        {
            printf("%4d", sarake*rivi);
        }
        numerot++;
        rivi++;
        if(rivi==16)
        {
            rivi=0;
            sarake++;
        }
    }

    return 0;
}
