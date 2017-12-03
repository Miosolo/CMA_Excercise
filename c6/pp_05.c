// display a reversal number

# include <stdio.h>
# include <math.h>

int main()
{
	int numraw, num, rev = 0;

	printf("Enter an integer above zero: ");
	scanf("%d", &numraw);

// How many digits?
	int digits = 0;
	num = numraw;
	do
	{
		num /= 10;
		digits++;
	} while (num > 0);

	printf("%d\n", digits);

// reverse
	num = numraw;
	for (int i; num > 0; digits--)
	{
		i = num % 10;
		rev += i * pow(10, digits - 1);
		num /= 10;
	}

	printf("The reversal number is %d\n", rev);

	return 0;
}
