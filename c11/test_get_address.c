#include <stdio.h>

int main(void)
{
    int a[3] = {0, 1}, *p = &a[0];

    for (int i = 0; i < 3; i++)
        printf("%d\t", *p++);
        
    getchar();
    return 0;
}