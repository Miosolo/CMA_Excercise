#include <stdio.h>
#include <stdbool.h>

void func(int num, int *odd, int *even, int *digits)
{
    int i;

    while(num > 0)
    {
        i = num % 10;
        if (i % 2 == 0)
            (*even)++;
        else
            (*odd)++;
        num /= 10;
    }
    *digits = *odd + *even;

    return;
}

int main(void)
{
    int testList[] = {45621, 2, 33, 5210, 44881, 7};
    int rightTable[][3] = {{5, 3, 2}, {1, 1, 0}, {2, 0, 2}, {4, 2, 2}, {5, 4, 1}, {1, 0, 1}};
    int odd, even, digits;
    bool correct = true;

    for (int i = 0; i < 6 && correct; i++)
    {
        odd = 0;
        even = 0;
        digits = 0;

        func(testList[i], &odd, &even, &digits);
        if (rightTable[i][0] == digits && rightTable[i][1] == even && rightTable[i][2] == odd)
            ;
        else
            correct = false;
    }

    if(correct)
        printf("Test passed.\n");
    else
        printf("Error occured.\n");

    return 0;
}