#include <stdio.h>
int main()
{
  int amount, rest, d20, d10, d5, d1;

  printf("Enter the dollar amout: ");
  scanf("%d", &amount);

  d20 = amount / 20;
  rest = amount - 20 * d20;
  d10 = rest / 10;
  rest = rest - 10 * d10;
  d5 = rest / 5;
  rest = rest - 5 * d5;
  d1 = rest;

  printf(
    "$20 bills: %d\n"
    "$10 bills: %d\n"
    "$5 bills: %d\n"
    "$1 bills: %d\n",d20, d10, d5, d1);
}
