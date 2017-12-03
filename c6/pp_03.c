// simplify a fraction
# include <stdio.h>
int main()
{
	int numer, denom, m, n, temp;

	printf("Enter a fraction: ");
	scanf("%d /%d", &numer, &denom);

	m = numer;
	n = denom;

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

	int GCD = m - n;
	printf("In lowest terms: %d/%d\n", numer / GCD, denom / GCD);

	return 0;
}
