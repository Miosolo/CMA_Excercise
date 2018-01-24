#include <stdio.h>
int main()
{
  float x;
  x=100/7.0;
  printf("original x eqals %f\n",x);
  printf("|%-8.1e|\n|%10.6e|\n|%-8.3f|\n|%6.0f|",x,x,x,x);
  return 0;
}
