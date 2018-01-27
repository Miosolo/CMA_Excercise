#include <stdio.h>

#define CUBIC(x) (x*x*x)
#define MOD_4(n) (n%4)
#define MULTIPLY_100(x,y) ((x*y>100)?1:0)

int main(void)
{
    printf("%f\n", CUBIC(0.5));
    printf("%d\n", MOD_4(2));
    printf("%d\n", MULTIPLY_100(24, 6));
}

