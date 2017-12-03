// sum up every row and column.

#include <stdio.h>
#define LENGTH_ROW 5
#define LENGTH_COLUMN 5

int main(void)
{
	int num[LENGTH_ROW][LENGTH_COLUMN] = {{0}},
		sum_row[LENGTH_ROW] = {0}, sum_column[LENGTH_COLUMN] = {0};

	for (int i = 0; i < LENGTH_ROW; i++)
	{
		printf("Enter row %d:\t", i + 1);
		for (int j = 0; j < LENGTH_COLUMN; j++)
			scanf("%d", &num[i][j]);
		fflush(stdin);
	}

	printf("Row totals:\t");
	for (int i = 0; i < LENGTH_ROW; i++)
	{
		for (int j = 0; j < LENGTH_COLUMN; j++)
			sum_row[i] += num[i][j];
		printf("%d\t", sum_row[i]);
	}
	printf("\n");

	printf("Column totals:\t");
	for (int j = 0; j < LENGTH_COLUMN; j++)
	{
		for (int i = 0; i < LENGTH_ROW; i++)
			sum_column[j] += num[i][j];
		printf("%d\t", sum_column[j]);
	}
	printf("\n");

	return 0;

}
