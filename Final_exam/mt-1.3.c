#include <stdio.h>

void srtArray(int array[], int num)
{
    int rem;
    while (num != 0)
    {
        rem = num % 10;
        array[rem]++;
        num /= 10;
    }

    return;
}

int isBeautifulExpr(int a, int b)
{
    int digitCounter[10] = {0};
    srtArray(digitCounter, a);
    srtArray(digitCounter, b);
    srtArray(digitCounter, a * b);

    for (int i = 0; i < 10; i++)
    {
        if (digitCounter[i] != 1)
            return 0;
    }

    return 1;
}

int main(void)
{
    int a = 1, b = 1, beauExpr = 0;

    while(a++ < 100)
    {
        for (b = 1; b < 10000; b++)
        {
            beauExpr += isBeautifulExpr(a, b);
        }
    }

    printf("Amount of beautiful expressions: %d.\n", beauExpr);

    return 0;
}

