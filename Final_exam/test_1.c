#include <stdio.h>

int main(void)
{
    int i = 1;
    while (i <= 10)
    {
        if (!(i % 2))
            printf("%d,", i);
        i++;
    }

    return 0;
}