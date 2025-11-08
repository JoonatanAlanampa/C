#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, i2, pituus, palindromi_lippu;
    char alkukirjain, loppukirjain, pieni_kirjainalku, pieni_kirjainloppu;

    for(i=1; i<argc; i++)
    {
        palindromi_lippu=1;
        pituus = strlen(argv[i]);
        for(i2=0; i2<pituus; i2++)
        {
            alkukirjain = argv[i][i2];
            pieni_kirjainalku = tolower(alkukirjain);

            loppukirjain = argv[i][pituus-i2-1];
            pieni_kirjainloppu = tolower(loppukirjain);

            if(pituus%2==0)
            {
                if(pieni_kirjainalku!=pieni_kirjainloppu)
                {
                    palindromi_lippu=0;
                    break;
                }
            }
            else
            {
                if(i2==pituus/2+1)
                {
                    continue;
                }
                else
                {
                    if(pieni_kirjainalku!=pieni_kirjainloppu)
                    {
                        palindromi_lippu=0;
                        break;
                    }
                }
            }
        }
        if(palindromi_lippu==1)
        {
            printf("\"%s\": on palindromi\n", argv[i]);
        }
        else
        {
            printf("\"%s\": ei ole palindromi\n", argv[i]);
        }
    }

    return 0;
}
