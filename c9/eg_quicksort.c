// quicksort under guideline of HackerRank
#include <stdio.h>

#define N 5

int medium(int a, int b, int c);
void swap(int *pa, int *pb);
void quicksort(int a[], int left, int right);

int main(void)
{
	int num[N];
	printf("Please input the entire array: ");
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	quicksort(num, 0, N - 1);

	printf("Sorted array: ");
	for (int i = 0; i < N; i++)
		printf("%d ", num[i]);

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

void quicksort(int a[], int left, int right)
{
	int pivot;
	int start = left, end = right;
	pivot = medium(a[left], a[right], a[(left + right) / 2]);

/*	while (right - left != 1)
	{	while (a[left] < pivot)
			do {left++;}
				while (right - left >= 1);
		while (a[right] > pivot)
			do	{right--;}
				while (right - left >= 1);

		if (right - left >= 1)
		{
			swap(&a[left], &a[right]);
			left++;
			right--;
		}
	}


	if (left != start)
		quicksort(a, start, left);
	if (end != right)
		quicksort(a, right, end);
*/


}
