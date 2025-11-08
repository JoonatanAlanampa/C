#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d)
{
  uint i, j, rivit=d-c+2, sarakkeet=b-a+2;
  
  Kertotaulu *t = malloc(sizeof(Kertotaulu));
  
  t->a = a;
  t->b = b;
  t->c = c;
  t->d = d;
  t->kertotaulu = malloc(rivit*sizeof(uint *));
  
  if(a>b || c>d)
  {
    free(t->kertotaulu);
    free(t);
    return NULL;
  }
  
  for(i=0; i<rivit; i++)
  {
    t->kertotaulu[i]=malloc(sarakkeet*sizeof(uint));
    for(j=0; j<sarakkeet; j++)
    {
      if(i==0 && j==0)
      {
        t->kertotaulu[i][j]=0;
      }
      else if(j==0)
      {
        t->kertotaulu[i][j]=c+i-1;
      }
      else if(i==0)
      {
        t->kertotaulu[i][j]=a+j-1;
      }
      else
      {
        t->kertotaulu[i][j]=(c+i-1)*(a+j-1);
      }
    }
  }
  
  return t;
}

void tuhoaKertotaulu(Kertotaulu *kt)
{
  uint i, rivit=kt->d-kt->c+2;
  for(i=0; i<rivit; i++)
  {
    free(kt->kertotaulu[i]);
  }
  
  free(kt->kertotaulu);
  free(kt);
}
