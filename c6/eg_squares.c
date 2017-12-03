#include <stdio.h>
int main()
{
	int lim, i = 1, square;

	printf
	(
		"This program prints a table of squares. \n"
		"Enter the number of entries in table: ");
	scanf("%d", &lim);

	while (i <= lim)
	{
		printf("%5d%10d\n", i, i * i);
		i++;
	}

	return 0;
}
