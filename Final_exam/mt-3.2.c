#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    printf("This programme is to solve ax^2+bx+c=0, so please enter the value below: \n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    b /= a;
    c /= a;
    a = 1;

    double delta = b * b - 4 * c;
    if (delta == 0)
    {
        double x;
        x = -(b / 2);
        printf("x1 = x2 = %f\n", x);
    }
    else if (delta > 0)
    {
        double alpha, beta;
        alpha = -b / 2;
        beta = sqrt(delta) / 2;
        printf("x1 = %f, x2 = %f\n", alpha + beta, alpha - beta);
    }
    else
    {
        double alpha, beta;
        alpha = -b / 2;
        beta = sqrt(-delta) / 2;
        printf("x1 = %f+%fi, x2 = %f+%fi\n", alpha, beta, alpha, beta);
    }

    return 0;
}