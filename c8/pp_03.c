//输入多个数，显示每个数字出现的次数
#include <stdio.h>

int main()
{
	int digits_repeat[10] = {0}, digit;
	long long num;

	for (num = 0; ;)
	{
		printf("Please input a number:");
		scanf("%lld", &num);

		if (num <= 0)
			break;
		else
		{
			for (; num > 0; )
			{
				digit = num % 10;
				digits_repeat[digit]++;
				num /= 10;
			}

			printf("Digit\t\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\nOccurance\t");
			for (int i = 0; i < 10; i++)
				printf("%d\t", digits_repeat[i]);
			printf("\n\n");
		}
	}

	return 0;
}
