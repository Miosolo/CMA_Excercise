// compare with several different dates.
# include <stdio.h>

int main()
{
	int dd1, mm1, yy1, dd2, mm2, yy2;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d /%d /%d", &mm1, &dd1, &yy1);

	for (int counter=1; 1; counter++)
	{
		printf("Enter next date (mm/dd/yy): ");
		scanf("%d /%d /%d", &mm2, &dd2, &yy2);

		if (mm2 == 0 && dd2 == 0 && yy2 == 0)
		break;

		if (yy2 < yy1)
		mm1 = mm2, dd1 = dd2, yy1 = yy2;
		else if (yy1 = yy2)
		{
			if (mm2 < mm1)
			mm1 = mm2, dd1 = dd2, yy1 = yy2;
			else if (mm2 = mm1)
			{
				if (dd2 < dd1)
				mm1 = mm2, dd1 = dd2, yy1 = yy2;
			}
		}
	}

	printf("%d / %d / %d is the earlist date.\n", mm1, dd1, yy1);

	return 0;
}
