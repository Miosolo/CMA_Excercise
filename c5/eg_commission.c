// compute the commission for a stock agent

#include <stdio.h>
int main()
{
  float trans, comm;

  printf("Enter value of trade: ");
  scanf("%f", &trans);

	if (trans < 0)
		{
			printf("You can't enter a minus number\n");
			return 0;
		}
	else if (trans < 2500)
		comm = 30 + 0.0017 * trans;
	else if (trans < 6250)
		comm = 56 + 0.0066 * trans;
	else if (trans < 20000)
		comm = 76 + 0.0034 * trans;
	else if (trans < 50000)
	 	comm = 100 + 0.0022 * trans;
	else if (trans < 500000)
		comm = 155 + 0.0011 * trans;
	else
		comm = 255 + 0.0009 * trans;

	if (comm < 39)
		comm = 39;

	printf("Commission: %.2f", comm);
	return 0;
}
