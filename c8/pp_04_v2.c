// promoted reversed.c
#include <stdio.h>
#define SIZE sizeof(num) / sizeof (num[0])

int main()
{
	int length;
	printf("Decide the amount of numbers you want to input: ");
	scanf("%d", &length);
	int num[length];

	printf("Enter a series of numbers: ");
	for (int i = 0; i < SIZE; i++)
		scanf("%d", &num[i]);

	printf("Reversed form: ");
	for (int i = SIZE - 1; i >= 0; i--)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}
