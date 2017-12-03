#include <stdio.h>
int main()
{
  int num1, denom1, num2, denom2, numf, denomf;
  
  printf("Enter two fractions separated by a plus sign: ");
  scanf("%d /%d +%d /%d", &num1, &denom1, &num2, &denom2);

  denomf = denom1 * denom2;
  numf = num1 * denom2 + num2 * denom1;

  printf("The sum is %d/%d", numf, denomf);
  return 0;
}
