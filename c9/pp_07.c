//more efficient power function

#include <stdio.h>

double power(double x, int index);

int main(void)
{
    double x;
    int index;

    printf("Please enter the value of x: ");
    scanf("%lf", &x);
    printf("Please enter the index: ");
    scanf("%d", &index);

    printf("x^n = %f", power(x, index));

    return 0;
}

double power(double x, int index)
{
    if (index == 1)
        return x;
    else if (index == 2)
        return x * x;
    else if (index % 2 == 0)
        return x * x * power(x, index - 2);
    else
        return x * power(x, index - 1);
}