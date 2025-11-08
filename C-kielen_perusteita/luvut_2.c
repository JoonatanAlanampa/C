#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a = atoi(argv[1]);
  
  int b = atoi(argv[2]);
  
  int tnrolkm = argc-3;
  
  int i, j, lippu=1, vika=3628800;
  
  for(i=b; i>=a; i--)
  {
    for(j=0; j<tnrolkm; j++)
    {
      if(i%atoi(argv[j+3])==0)
      {
        lippu=0;
        break;
      }
    }
    if(lippu==1)
    {
      vika=i;
      break;
    }
    lippu=1;
  }
  
  if(vika==3628800)
  {
    return 0;
  }
  
  for(i=a; i<=b; i++)
  {
    for(j=0; j<tnrolkm; j++)
    {
      if(i%atoi(argv[j+3])==0)
      {
        lippu=0;
        break;
      }
    }
    if(lippu==1)
    {
      if(i==vika)
      {
        printf("%d\n", i);
      }
      else
      {
        printf("%d ", i);
      }
    }
    lippu=1;
  }
  
  return 0;
}
