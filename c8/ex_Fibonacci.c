# include <stdio.h>
# define N 40

int main()
{
	int j;
	int Fibo[N];

	Fibo[0] = 1;
	Fibo[1] = 1;

	for (j = 2; j < N; j++)
	{
		Fibo[j] = Fibo[j -1] + Fibo[j -2];
	}

	for (int i = 0; i < N; i++)
	printf("%d\n", Fibo[i]);

	return 0;
}
