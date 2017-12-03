// 计算条形码中的校验码 v2.0

#include <stdio.h>
int main()
{
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;

  printf("Enter the first 11 digits of a UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &num1, &num2, &num3, &num4, &num5,
  &num6, &num7, &num8, &num9, &num10, &num11);

  int sum1, sum2;
  sum1 = num1 + num3 + num5 + num7 + num9 + num11;
  sum2 = num2 + num4 + num6 + num8 + num10;
  num12 = sum1 * 3 + sum2;
  num12 -= 1;
  num12 %= 10;
  num12 = 9 - num12;

 printf("Check digit : %d", num12);

 return 0;
}
