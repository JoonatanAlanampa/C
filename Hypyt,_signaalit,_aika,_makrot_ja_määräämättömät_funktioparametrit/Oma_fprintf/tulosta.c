#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include "tulosta.h"

size_t tulosta(FILE *td, const char *mj, ...)
{
    size_t laskuri=0, i, pituus=strlen(mj);

    int x, n, kerroin, tmp;

    char *s;

    char c;

    va_list pl;

    va_start(pl, mj);

    for(i=0; i<pituus; i++)
    {
        if(mj[i]!='%')
        {
            fputc(mj[i], td);
            laskuri++;
        }
        else
        {
            if(mj[i+1]=='%')
            {
                fputc('%', td);
                laskuri++;
            }
            else if(mj[i+1]=='d')
            {
                x = va_arg(pl, int);

                if (x < 0)
                {
                    fputc('-', td);
                    laskuri++;
                    x = -x;
                }

                kerroin = 1;
                tmp=x;

                while(tmp>=10)
                {
                    kerroin*=10;
                    tmp/=10;
                }

                while(kerroin>0)
                {
                    n=(x/kerroin)%10;
                    fputc('0' + n, td);
                    laskuri++;
                    kerroin/=10;
                }
            }
            else if(mj[i+1]=='s')
            {
                s = va_arg(pl, char *);
                while(*s)
                {
                    fputc(*s++, td);
                    laskuri++;
                }
            }
            else if(mj[i+1]=='c')
            {
                c = (char)va_arg(pl, int);
                fputc(c, td);
                laskuri++;
            }
            i++;
        }
    }

    va_end(pl);

    return laskuri;
}
