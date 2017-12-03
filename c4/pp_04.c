// convert a 10-based number into a 8-based one

#include <stdio.h>

int main()
{
  int raw, num1, num2, num3, num4, num5, num6;

  printf("Enter a number between 0 and 32767 :");
  scanf("%d", &raw);

  if(raw > 32767 || raw < 0)
  {
    printf("The number is out of range.\n");
    return 0;
  }

  else
  {
    num1 = raw / (8 * 8 * 8 * 8 * 8);
    num2 = raw / (8 * 8 * 8 * 8) % 8;
    num3 = raw / (8 * 8 * 8) % 8;
    num4 = raw / (8 * 8) % 8;
    num5 = raw / (8) % 8;
    num6 = raw % 8;

   printf("In octal, your number is: %d%d%d%d%d%d", num1, num2, num3, num4, num5, num6);
   return  0;
  }
}
