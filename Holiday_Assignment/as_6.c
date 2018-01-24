#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 20

int maxArray(int *arr)
{
    int *p = arr, *maxPosi = p;
    for (p++; p < arr + LEN; p++)
    {
        if (*p > *maxPosi)
            maxPosi = p;
    }

    return maxPosi - arr;
}

int main(void)
{
    int numArr[LEN];
    srand(time(0));
    printf("The random number array:");
    for (int i = 0; i < LEN; i++)
    {
        numArr[i] = rand() % 50;
        printf("  %d", numArr[i]);
    }
    printf("\n");

    int maxIndex = maxArray(numArr);
    printf("Max=  %d, Index=  %d", numArr[maxIndex], maxIndex);

    return 0;
}