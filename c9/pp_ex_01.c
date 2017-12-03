// GCD & LCM in function
#include <stdio.h>

int gcd(int, int);
int lcd(int, int);

int main(void)
{
	int num1, num2;

	printf("Please enter 2 integers: ");
	scanf("%d%d", &num1, &num2);

	printf("The GCD is %d.\n", gcd(num1, num2));
	printf("The LCD is %d.\n", lcd(num1, num2));

	return 0;
}

int gcd(int a, int b)
{
	if (!b)
		return a;
	else
		return gcd(b, a % b);
}

int lcd(int a, int b)
{
	return a * b / gcd(a, b);
}
