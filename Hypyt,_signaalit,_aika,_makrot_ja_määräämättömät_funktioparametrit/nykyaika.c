#include <time.h>
#include <stdio.h>

int main()
{
    time_t a = time(NULL);

    char aika[40];

    struct tm *b = localtime(&a);

    char *vp;

    if(b->tm_wday==0)
    {
        vp="Sunnuntai";
    }
    else if(b->tm_wday==1)
    {
        vp="Maanantai";
    }
    else if(b->tm_wday==2)
    {
        vp = "Tiistai";
    }
    else if(b->tm_wday==3)
    {
        vp = "Keskiviikko";
    }
    else if(b->tm_wday==4)
    {
        vp = "Torstai";
    }
    else if(b->tm_wday==5)
    {
        vp = "Perjantai";
    }
    else if(b->tm_wday==6)
    {
        vp = "Lauantai";
    }

    strftime(aika, 40, "%d.%m.%Y klo %H:%M", b);

    printf("%s %s\n", vp, aika);

    return 0;
}
