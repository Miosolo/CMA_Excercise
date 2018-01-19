#include <stdio.h>

int main(void)
{
    double current, nextNumber;
    char oprater;

    printf("Enter an expression: ");
    scanf("%lf", &current);

    while ((oprater = getchar()) != '\n')
    {
        scanf("%lf", &nextNumber);
        switch (oprater)
        {
            case '+':
                current += nextNumber;
                continue;
            case '-':
                current -= nextNumber;
                continue;
            case '*':
                current *= nextNumber;
                continue;
            case '/':
                current /= nextNumber;
                continue;
            default:
                printf("Error: unsupported oprater.\n");
                return 0;
                continue;
        }
    }

    printf("Value of expression: %f", current);

    return 0;
}