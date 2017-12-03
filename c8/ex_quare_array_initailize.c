#include <stdio.h>
#define SIZE 20

int main()
{
	int a[SIZE][SIZE] = {0}, col, row;

	for (int i = 0; i < SIZE; i++)
		a[i][i] = 1;

	for (row = 0; row < SIZE; row++)
	{
		for (col = 0; col < SIZE; col++)
			printf("%d\t", a[row][col]);
		printf("\n");
	}

	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += a[i][i];
	}
	printf("The sum of this array is %d.\n", sum);

	return 0;
}
