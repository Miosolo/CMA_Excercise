// quicksort under guideline of HackerRank
#include <stdio.h>
#include <stdbool.h>

#define N 14

int a[N];

int medium(int a, int b, int c);
void swap(int *pa, int *pb);
void quicksort(int left, int right);

int main(void)
{
	printf("Please input the entire array: ");
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	quicksort(0, N - 1);

	printf("Sorted array: ");
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);

	return 0;
}

void swap(int *pa, int *pb)
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int medium(int a, int b, int c)
{
	if ((a - b) * (b - c) >= 0)
		return b;
	else
		return b > c ? (a > c ? a : c) : (a > c ? c : a);
}

void quicksort(int left, int right)
{	
	//if 1 number
	if (right - left == 0)
		return;

	//if 2 numbers(quicksort cannot solve)
	if (right - left == 1)
	{
		if (a[left] > a[right])
		{
			swap(&a[left], &a[right]);
			return;
		}
		else
			return;
	}

	//my quicksort could arrange >=3 numbers
	//initialize
	int pivot, gap = right - left;
	int start = left, end = right;
	bool next_round = false;

	pivot = medium(a[left], a[right], a[(left + right) / 2]);

	//find numbers out of range
	while (!next_round)
	{	while (gap > 0 && a[left] <= pivot)
		{
			left++;
			gap--;
		}
		while (gap > 0 && a[right] >= pivot)
		{
			right--;
			gap--;
		}

		if (gap == 0)
		{
			left--;
			next_round = true;
		}

		if (!next_round)
		{
			swap(&a[left], &a[right]);
		}

	}

	quicksort(start, left);
	quicksort(right, end);

	return;
}
