#include <stdio.h>

int sum(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

int main (void)
{
	int grades[10];

	printf("Enter 10 grades: ");
	for (int i = 0; i < 10; i++)
		scanf("%d", &grades[i]);

	printf("The sum is %d.\n", sum(grades, 10));
	printf("%d", q);

	return 0;
}
