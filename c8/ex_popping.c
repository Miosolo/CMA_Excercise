// popping arrangement for N numbers (from smaller to lager)

#include <stdio.h>
#define N 10

int main()
{
	int m[N];
	int j = 0, t;

	printf("Iuput 10 numbers: ");

	for (int i = 1; i <= N; i++)
	scanf("%d", &m[j++]);

	for (int counter = 1; counter < N; counter++)
	{
		for (j = 0; j < N  - counter; j++)
		{
			if (m[j] > m[j + 1])
			{
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}

	for (int i = 0; i < N; i++)
	printf("%d\t", m[i]);

	return 0;
}
