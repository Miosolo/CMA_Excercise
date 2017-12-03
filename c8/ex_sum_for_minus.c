#include <stdio.h>

int main()
{
	int num[10] = {10, -20, -10, 4, -2, -3, 11, -90, 20, -5};
	int sum = 0, i;

	for (i = 0; i <= 9; i++)
	{
		if (num[i] < 0)
			sum += num[i];
	}
	printf("sum = %6d\n", sum);
}
