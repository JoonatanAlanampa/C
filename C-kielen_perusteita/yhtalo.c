#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    if(b*b-4*a*c<0)
    {
        printf("Ei ratkaisua\n");
    }
    else if(b*b-4*a*c==0)
    {
        printf("%.3f\n", -b/(2*a));
    }
    else
    {
        printf("%.3f ", (-b-sqrt(b*b-4*a*c))/(2*a));
        printf("%.3f\n", (-b+sqrt(b*b-4*a*c))/(2*a));
    }


    return 0;
}
