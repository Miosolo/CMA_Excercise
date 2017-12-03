#include <stdio.h>
int main ()
{
  float original, total;
  printf("Enter an amount: ");
  scanf("%f", &original);
  total = original * 1.05;
  printf("With tax added: $%.2f\n", total);
  return 0;
}
