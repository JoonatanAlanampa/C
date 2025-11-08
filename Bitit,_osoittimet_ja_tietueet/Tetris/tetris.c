#include "tetris.h"

void paivita(char ruudukko[20][10])
{
    int i, i2, j, laskuri=0;

    for(i=0; i<20; i++)
    {
        for(j=0; j<10; j++)
        {
            if(ruudukko[i][j] != ' ')
            {
                laskuri++;
                if(laskuri==10)
                {
                    for(i2=i; i2>=0; i2--)
                    {

                        for(j=0; j<10; j++)
                        {
                            if(i2!=0)
                            {
                                ruudukko[i2][j]=ruudukko[i2-1][j];
                            }
                            else
                            {
                                ruudukko[i2][j] = ' ';
                            }
                        }
                    }
                }
            }
        }
        laskuri=0;
    }
}
