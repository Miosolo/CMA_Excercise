//arrange a list of integers.

#include <stdio.h>
#include <ctype.h>

void swap(int *pa, int *pb);
void selection_sort(int a[], int n);

int main(void)
{
    //build the array
    int length;
    printf("Please enter the amount of integers: ");
    scanf("%d", &length);
    int num[length];

    //input
    printf("Please input %d numbers: \n", length);
    for (int i = 0; i < length; i++)
        scanf("%d", num + i);

    selection_sort(num, length);

    printf("Sorted numbers: ");
    for (int i = 0; i < length; i++)
        printf("%d ", *(num + i));
    printf("\n");

    return 0;
}

void swap(int *pa, int *pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;

    return;
}

void selection_sort(int a[], int n)
{
    int i, max_position = 0;

    for (i = 0; i < n; i++)
    {
        if (*(a + i) > *(a + max_position))
            max_position = i;
    }

    swap(a + max_position, a + n - 1);
    
    if (n > 2)
        selection_sort(a, n - 1);

    return;
}