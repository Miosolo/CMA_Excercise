#include <stdio.h>

int main()
{
	int i;

	for (i = 50; i < 100; i++)
	{
		if (i % 2 == 0 || i % 3 == 0 || i % 7 == 0)
			continue;
		printf("%d\n", i);
	}
}
