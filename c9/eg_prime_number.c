// Test whether a number is prime.

#include <stdio.h>
#include <stdbool.h>

bool prime(int);

int main(void)
{
	int n;

	printf("Enter a number for testing: ");
	scanf("%d", &n);

	if (prime(n))
		printf("This is a prime number.\n");
	else
		printf("This is not a prime number.\n");

	return 0;
}

bool prime(int num)
{
	int i;

	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
