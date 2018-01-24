#include <stdio.h>
int main()
{
  int num1, num2, numf, denom1, denom2, denomf;
  printf("Enter the first fraction (okay to include spaces) :\n");
  scanf("%d /%d", &num1, &denom1);
  printf("Enter the second fraction (okay to include spaces) :\n");
  scanf("%d /%d", &num2, &denom2);
  denomf = denom1 * denom2;
  numf = num1 * denom2 + num2 * denom1;
  printf("The added fraction is %d/%d", numf, denomf);
  return 0;
}
