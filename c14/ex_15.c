#include <stdio.h>

#define ENGLISH 1

#ifdef ENGLISH
#define PRINT_LANGUAGE printf("English.\n")
#elif FRENCH
#define PRINT_LANGUAGE printf("French.\n")
#elif SPANISH
#define PRINT_LANGUAGE printf("Spanish.\n")
#endif


int main(void)
{
    PRINT_LANGUAGE;
}