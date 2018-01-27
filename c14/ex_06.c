#include <stdio.h>
#include <math.h>

#define DISP(opreation, value) printf(#opreation "(%g) = %g\n", value, opreation(value));

int main(void)
{
    DISP(sqrt, 3.0);
}