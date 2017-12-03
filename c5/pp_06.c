// verify the validity of UPC

# include <stdio.h>

int main()
{
	int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;

  printf("Enter full UPC code: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
		&num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12);

  int sum1, sum2, t;
  sum1 = num1 + num3 + num5 + num7 + num9 + num11;
  sum2 = num2 + num4 + num6 + num8 + num10;
  t = sum1 * 3 + sum2;
 	t -= 1;
  t %= 10;

  t = 9 - t;

	if (t == num12)
	printf("VALID\n");
	else
	printf("NOT VALID\n");

 return 0;
}
