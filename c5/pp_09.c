// compare between 2 dates
# include <stdio.h>

int main()
{
	int mm1, dd1, yy1, mm2, dd2, yy2;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d /%d /%d", &mm1, &dd1, &yy1);
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d /%d /%d", &mm2, &dd2, &yy2);

	if (yy1 < yy2)
	printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", mm1, dd1, yy1, mm2, dd2, yy2);
	else if (yy2 < yy1)
	printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", mm2, dd2, yy2, mm1, dd1, yy1);
	else
	{
		if (mm1 < mm2)
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", mm1, dd1, yy1, mm2, dd2, yy2);
		else if (mm2 < mm1)
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", mm2, dd2, yy2, mm1, dd1, yy1);
		else
		{
			if (dd1 < dd2)
			printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", mm1, dd1, yy1, mm2, dd2, yy2);
			else if (dd2 < dd1)
			printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", mm2, dd2, yy2, mm1, dd1, yy1);
			else
			printf("%d/%d/%.2d is equal to %d/%d/%.2d\n", mm1, dd1, yy1, mm2, dd2, yy2);
		}
	}
	return 0;
}
