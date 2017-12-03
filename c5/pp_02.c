// 24-hour to 12-hour
# include <stdio.h>

int main()
{
	int hh, mm;

	printf("Enter a 24-hour time: (hh:mm)");
	scanf("%d :%d", &hh, &mm);

	if (hh >= 0 && hh <=12)
	{
		if (hh != 12)
		printf("Equivalent 12-hour time: %.2d:%.2d AM.\n", hh, mm);
		else
		printf("Equivalent 12-hour time: %.2d:%.2d PM.\n", hh, mm);
	}
	else if (hh <= 23)
	printf("Equivalent 12-hour time: %.2d:%.2d PM.\n", hh - 12, mm);
	else if (hh == 24 && mm == 0)
	printf("Equivalent 12-hour time: 00:00 AM\n");
	else
	printf("Invalid time.\n");

	return 0;
}
