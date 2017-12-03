#include <stdio.h>

int main()
{
	int n, sum = 0;

	printf
	(
		"This program sums a series of integers.\n"
		"Enter integers (0 to terminate):"
	);

	do
	{
		scanf("%d", &n);
		sum += n;
	}
	while (n != 0);

	printf("The sum is %d\n", sum);

	return 0;

}
