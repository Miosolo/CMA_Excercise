// popping arrangement for N numbers (from smaller to lager)

#include <stdio.h>
#define N 10

void swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;

    return;
}

    int main()
{
	int arr[N];
	int j = 0;

	printf("Iuput %d numbers: ", N);

	for (int i = 1; i <= N; i++)
	scanf("%d", &arr[j++]);


    int unsorted = N - 1;
    for (int i = 1; i < N; i++)
	{
        int limit = unsorted;
        for (j = 0; j <= limit; j++)
		{
			if (arr[j] > arr[j + 1])
			{
                swap(&arr[j], &arr[j + 1]);
                unsorted = j;
            }
		}
	}

	for (int i = 0; i < N; i++)
	printf("%d\t", arr[i]);

	return 0;
}
