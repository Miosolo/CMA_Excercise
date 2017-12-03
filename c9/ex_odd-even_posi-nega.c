#include <stdio.h>
#include <stdbool.h>

bool odd(int num);
bool positive(int num);

int main(void)
{
	int num;

	printf("Enter an integer for testing: ");
	scanf("%d", &num);

	if (odd(num))
		printf("This is an odd number.\n");
	else
		printf("This is an even number.\n");

	if (positive(num))
		printf("This is a positive number.\n");
	else
		printf("This is not a positive number.\n");

	return 0;
}

bool odd(int num)
{
	if (num % 2 != 0)
		return true;
	return false;
}

bool positive(int num)
{
	if (num > 0)
		return true;
	return false;
}
