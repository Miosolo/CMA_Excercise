// reverse a 3-digits number

#include <stdio.h>
int main()
{
  int raw, num100, num10, num1;
  printf("Enter a three-digit number : ");
  scanf("%d", &raw);

  num100 = raw / 100;
  num10 = raw / 10 % 10;
  num1 = raw % 10;

  printf("The reversal is : %d\n", num1 * 100 + num10 * 10 + num100);

  return 0;
}
