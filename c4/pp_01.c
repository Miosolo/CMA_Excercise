// reverse a 2-digits number

#include <stdio.h>
int main()
{
  int raw, num10, num1;
  printf("Enter a two-digit number : ");
  scanf("%d", &raw);

  num10 = raw / 10;
  num1 = raw % 10;

  printf("The reversal is : %d\n", num1 * 10 + num10);

  return 0;
}
