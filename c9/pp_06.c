//calculate the value of a polynomial(fixed expression)

#include <stdio.h>

double power(double x, int (index));
double f(double x);

int main(void)
{
    double x;

    printf("Please enter the value of x: ");
    scanf("%lf", &x);

    printf("The value of function is %f", f(x));

    return 0;
}

double f(double x)
{
    return (3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2) + 7 * x - 6);
}

double power(double x, int index)
{
    if (index == 1)
        return x;
    else
        return x * power(x, index - 1);
}