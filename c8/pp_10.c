//search the flight

#include <stdio.h>
#include <stdlib.h>
#define FLIGHTS 8

int main(void)
{
	//initialize
	const int off_hour[FLIGHTS] = {8, 9, 11, 12, 14, 15, 19, 21}, off_minute[FLIGHTS] = {0, 43, 19, 47, 0, 45, 0, 45},
		landing_hour[FLIGHTS] = {10, 11, 13, 15, 16, 17, 21, 23}, landing_minute[FLIGHTS] = {16, 52, 31, 0, 8, 55, 20, 58};
	int hour_diff[FLIGHTS] = {0}, minute_diff[FLIGHTS] = {0}, hour, minute, order;

	printf("Enter a 24-hour time (hh:mm): ");
	scanf("%d :%d", &hour, &minute);

	//look for closest flight
	for(order = 0; ;order++)
	{
		hour_diff[order] = abs(hour - off_hour[order]);
		minute_diff[order] = abs(minute - off_minute[order]);
		if (order >= 1)
		{
			if (hour_diff[order] > hour_diff[order - 1])
				break;
			else if (hour_diff[order] == hour_diff[order - 1])
			{
				if (minute_diff[order] >= minute_diff[order - 1])
					break;
			}
		}
	}
	order--;

	//print
	printf("The closest departure time is ");
	if (off_hour[order] < 12)
	{
		if (landing_hour[order] < 12)
			printf("%d:%.2d a.m., arriving at %d:%.2d a.m.\n", off_hour[order], off_minute[order], landing_hour[order], landing_minute[order]);
		else if (landing_hour[order] == 12)
			printf("%d:%.2d a.m., arriving at 12:%.2d p.m.\n", off_hour[order], off_minute[order], landing_minute[order]);
		else
			printf("%d:%.2d a.m., arriving at %d:%.2d p.m.\n", off_hour[order], off_minute[order], landing_hour[order] - 12, landing_minute[order]);
	}
	else if (off_hour[order] == 12)
	{
		if (landing_hour[order] == 12)
			printf("12:%.2d p.m., arriving at 12:%.2d p.m.\n", off_minute[order], landing_minute[order]);
		else
			printf("12:%.2d p.m., arriving at %d:%.2d p.m.\n", off_minute[order], landing_hour[order] - 12, landing_minute[order]);
	}
	else
		printf("%d:%.2d p.m., arriving at %d:%.2d p.m.\n", off_hour[order] - 12, off_minute[order], landing_hour[order] - 12, landing_minute[order]);

	return 0;
}
