#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int tarkkuus = atoi(argv[1]);
  int i, lkm=argc-2;
  
  for(i=0; i<lkm; i++)
  {
    printf("sqrt(%.*f) = %.*f\n", tarkkuus, atof(argv[i+2]), tarkkuus, sqrt(atof(argv[i+2])));
  }
  
  return 0;
}
