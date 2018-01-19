#include <stdio.h>

int main(void)
{
    int numArr[] = {6, 5, 8, 1, 0, 4, 7, 3, 2, 9};
    int bucket[10] = {0};

    for (int i = 0; i < (int)sizeof(numArr) / sizeof(numArr[0]); i++)
    {
        bucket[numArr[i]]++;
    }

    printf("Sorted array: ");
    for (int i = 0; i < (int)sizeof(bucket) / sizeof(bucket[0]); i++)
    {
        while(bucket[i] > 0)
        {
            printf("%d ", i);
            bucket[i]--;
        }
    }
    printf("\n");

    return 0;
}