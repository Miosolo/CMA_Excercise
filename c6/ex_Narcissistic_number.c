//计算所有的三位水仙花数（N位整数每一位的N次幂为自身）

#include <stdio.h>

int main()
{
	int nraw, n100, n10, n1;

	for (int No = 1, nraw = 100; nraw < 1000; nraw++)
	{

		n100 = nraw / 100;
		n10 = nraw / 10 % 10;
		n1 = nraw % 10;

		if (n100 * n100 * n100 + n10 * n10 * n10 + n1 * n1 * n1 == nraw)
		{
			printf("the No.%d Narcissistic number is %d\n", No++, nraw);
		}
	}

	return 0;
}
