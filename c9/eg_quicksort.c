// quicksort under guideline of HackerRank
#include <stdio.h>

int medium(int a, int b, int c);
void swap(int *pa, int *pb);
void quicksort(int a[], int left, int right);

int main(void)
{
	int n;
	printf("Enter the array's length: ");
	scanf("%d", &n);

	int num[n];
	printf("Please input the entire array: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	quicksort(num, n);

	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
		printf("%d", num[i]);

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
	pivot = medium(a[left], a[right], a[(left + right) / 2]);

	while (a[left] <= pivot)
		left++;
	left++;

	while (a[right] >= pivot)
		right--;
	right--;

}
