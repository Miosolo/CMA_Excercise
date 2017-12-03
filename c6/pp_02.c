// compute the GCD

#include <stdio.h>

int main()
{
	int m, n, temp;

	printf("Enter two integers: ");
	scanf("%d%d", &m, &n);

	if (m > n)
	{
		temp = m;
		m = n;
		n = temp;
	}

	do
	{
		temp = n;
		n = m % n;
		m = temp;
	}
	while (n != 0);

	printf("Greatest common divisor: %d\n", m - n);

	return 0;
}
