#include <stdio.h>

int main()
{
	int num, digits = 0;

	printf("Enter a number: ");
	scanf("%d", &num);

	int num_raw;
	num_raw = num;

	while (num != 0)
	{
		num = num / 10;
		digits++;
	}

	printf("The number %d has %d digits.\n", num_raw, digits);

	return 0;
}
