#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i, lkm=strlen(argv[1]), summa=0;
  
  for(i=0; i<lkm; i++)
  {
    if(argv[1][i] == '1')
    {
      if(i==0)
      {
        summa-=pow(2, lkm-1);
        continue;
      }
      summa+=pow(2, lkm-i-1);
    }
  }
  
  
  printf("%d\n", summa);
  
  return 0;
}
