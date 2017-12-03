// display a table of squares (24 numbers as a group)
#include <stdio.h>
int main()
{
	int lim, i = 1, square;

	printf
	(
		"This program prints a table of squares. \n"
		"Enter the number of entries in table: ");
	scanf("%d", &lim);
	// to consume the ramaining \n
	getchar();

	while (i <= lim)
	{
		printf("%5d%10d\n", i, i * i);
		i++;
		if (i % 24 != 0)	continue;
		printf("Press Enter to continue...\n");
		if (getchar() != '\n')	break;
	}

	return 0;
}
