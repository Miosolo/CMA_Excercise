#include <stdio.h>

int main(void)
{
    union num {
        int i;
        double d;
    } Arr[20] = {{1}};

    printf("%d", Arr[1].i);
}