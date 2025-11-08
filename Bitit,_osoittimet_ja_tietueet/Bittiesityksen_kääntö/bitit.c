#include <limits.h>

void kaannaScharBitit(signed char *x)
{
    int i, i2=0, tmp1, tmp2;

    for(i=CHAR_BIT*sizeof(signed char)-1; i>=i2; i--)
    {
        tmp1 = ((*x >> i) & 1);
        tmp2 = ((*x >> i2) & 1);
        if(tmp1!=tmp2)
        {
            if(tmp1==1)
            {
                *x = *x & ~(1 << i);
                *x = *x | (1 << i2);
            }
            else
            {
                *x = *x & ~(1 << i2);
                *x = *x | (1 << i);
            }
        }
        i2++;
    }

}

void kaannaShortBitit(short *x)
{
    int i, i2=0, tmp1, tmp2;

    for(i=CHAR_BIT*sizeof(short int)-1; i>=i2; i--)
    {
        tmp1 = ((*x >> i) & 1);
        tmp2 = ((*x >> i2) & 1);
        if(tmp1!=tmp2)
        {
            if(tmp1==1)
            {
                *x = *x & ~(1 << i);
                *x = *x | (1 << i2);
            }
            else
            {
                *x = *x & ~(1 << i2);
                *x = *x | (1 << i);
            }
        }
        i2++;
    }
}

void kaannaIntBitit(int *x)
{
    int i, i2=0, tmp1, tmp2;

    for(i=CHAR_BIT*sizeof(int)-1; i>=i2; i--)
    {
        tmp1 = ((*x >> i) & 1);
        tmp2 = ((*x >> i2) & 1);
        if(tmp1!=tmp2)
        {
            if(tmp1==1)
            {
                *x = *x & ~(1 << i);
                *x = *x | (1 << i2);
            }
            else
            {
                *x = *x & ~(1 << i2);
                *x = *x | (1 << i);
            }
        }
        i2++;
    }
}

void kaannaLongBitit(long *x)
{
    long int i, i2=0, tmp1, tmp2;

    for(i=CHAR_BIT*sizeof(long int)-1; i>=i2; i--)
    {
        tmp1 = ((*x >> i) & 1);
        tmp2 = ((*x >> i2) & 1);
        if(tmp1!=tmp2)
        {
            if(tmp1==1)
            {
                *x = *x & ~(1L << i);
                *x = *x | (1L << i2);
            }
            else
            {
                *x = *x & ~(1L << i2);
                *x = *x | (1L << i);
            }
        }
        i2++;
    }
}
