#include <stdio.h>

int main()
{
  int i;
  
  for(i=1; i<101; i++)
  {
    if(i%2==0 || i%3==0 || i%5==0)
    {
      continue;
    }
    else
    {
      if(i==97)
      {
        printf("%d\n", i);
      }
      else
      {
        printf("%d ", i);
      }
    }
  }
  
  return 0;
}
