// 按照月利率计算收益
#include <stdio.h>
#include <math.h>
#define NUM_RATES 5
#define INITIAL_BALANCE 100

int main()
{
	int years;
	double value[NUM_RATES], initial_annual_rate,
		annual_rate[NUM_RATES], monthly_rate[NUM_RATES];

	printf("Enter interest rate: ");
	scanf("%lf", &initial_annual_rate);
	printf("Enter number of years: ");
	scanf("%d", &years);

// initialize
	printf("Years\t");
	for (int i = 0; i < NUM_RATES; i++)
	{
		annual_rate[i] = initial_annual_rate + i;
		printf("%.3f%%\t", annual_rate[i]);
		monthly_rate[i] = annual_rate[i] / 12;
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

// compute
	for (int i = 0; i < years; i++)
	{
		printf("%d\t", i + 1);
		for (int j = 0; j < NUM_RATES; j++)
		{
			value[j] *= pow(monthly_rate[j] / 100 + 1, 12);
			printf("%.3f\t", value[j]);
		}
		printf("\n");
	}

	return 0;
}
