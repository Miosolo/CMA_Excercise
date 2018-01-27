#include <stdio.h>

#define ENGLISH 1

int main(void)
{
#ifdef ENGLISH
    printf("English.\n");
#elif FRENCH
    printf("French.\n");
#elif SPANISH
    printf("Spanish.\n");
#endif
}