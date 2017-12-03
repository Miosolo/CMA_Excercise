//print out a calendar for a month
# include <stdio.h>
int main()
{
	int day = 1, start, limit;

	printf("Enter number of days in month: ");
	scanf("%d", &limit);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &start);

	printf("\n\n");

	for (int blank = start - 1; blank != 0; blank--)
	printf("\t");

	for (int location = start; day <= limit; day++, location++)
	{
		printf("%2d\t", day);
		if (location % 7 == 0)
		printf("\n");
	}
	printf("\n\n");

	return 0;
}
