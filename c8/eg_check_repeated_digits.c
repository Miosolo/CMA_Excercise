#include <stdio.h>
#include <stdbool.h>

int main()
{
	bool digit_occur[10] = {false};
	int digit;
	long num;

	printf("Enter a number:");
	scanf("%ld", &num);

	for (; num > 0; )
	{
		digit = num % 10;
		if (digit_occur[digit])
			break;
		digit_occur[digit] = true;
		num = 10;
	}

	if (num > 0)
		printf("Repeated digits.\n");
	else
		printf("No repeated digits.\n");

	return 0;
}
