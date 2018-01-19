#include <stdio.h>

int factorial(int num)
{
    if (num == 1 || num == 0)
        return 1;

    int temp = num;
    while (temp > 1)
    {
        num *= --temp;
    }

    return num;
}

int main(void)
{
    int a, b, c;

    printf("Please input the value of a: ");
    scanf("%d", &a);
    printf("Please input the value of b: ");
    scanf("%d", &b);
    printf("Please input the value of c: ");
    scanf("%d", &c);

    printf("a!+b!+c! = %d", factorial(a) + factorial(b) + factorial(c));

    return 0;
}