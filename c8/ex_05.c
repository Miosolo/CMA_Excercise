#include <stdio.h>
#define N 4

int main()
{
	int i, j, a[N] = {17, 4, 9, 12}, b[N] = {13, 1, 24, 10};

	for (i = 0; i < N; i++)
	{
		for (j = N - 1; j >= 0; j--)
		{
			if (a[i] > b[j])
				printf("%d ", b[j]);
		}
	}
	printf("\n");
}
