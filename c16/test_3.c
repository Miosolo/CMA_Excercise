#include <stdio.h>

int main(void)
{
    enum suit
    {
        YES = 1,
        NO = 0
    } a, b;

    a = YES;
    b = NO;
    b++;
    printf("%d", b);
    
}