#include <stdio.h>
#define N 7

void quicksort(int a[], int left, int right)
{
    int pivot;
    int start = left, end = right;
	pivot = medium(a[left], a[right], a[(left + right) / 2]);

	while (right - left != 1)
	{	while (a[left] < pivot)
			left++;
		while (a[right] > pivot)
			right--;

		swap(&a[left], &a[right]);
		left++;
		right--;
	}

	if (right - left == 1)
		exit(0);

	quicksort(a, start, left);
	quicksort(a, right, end);
}

int main(void)
{
    int a[N] = {1, 5, 3, 2, 6, 0, 7}, left = 0, right = N - 1;

    quicksort(a, left, right);

    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);

    return 0;
}
