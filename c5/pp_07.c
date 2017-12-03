//find MAX and min number among 4 numbers
# include <stdio.h>

int main()
{
	int a, b, c, d, m, M, m1, M1;

	printf("Enter four integers: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);

	if (a > b)
	M = a, m = b;
	else
	M = b, m = a;

	if (c > d)
	m1 = d, M1 = c;
	else
	m1 = c, M1 = d;

	if (m1 < m)
	m = m1;

	if (M1 > M)
	M = M1;
	
	printf("Largest: %d\n", M);
	printf("Smallest: %d\n", m);

	return 0;
}
