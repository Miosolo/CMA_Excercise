#include <stdio.h>

#define SIZE_OF_ARR(arr) sizeof(arr)/sizeof(arr[0])

int main(void)
{
    int arr[10] = {0};
    printf("%d", SIZE_OF_ARR(arr));
}