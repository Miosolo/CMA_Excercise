// 显示1~n中所有偶数的平方和

#include <stdio.h>

int main()
{
	int limit, i, square;

	printf("Enter the limit of n^2: ");
	scanf("%d", &limit);

	for (i = 1; 4 * i * i <= limit; i++)
	{
		printf("%d\n", 4 * i * i);
	}

	return 0;
}
