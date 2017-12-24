#include <stdio.h>

#define MAX_LENGTH 200

int main (void)
{
    char sentence[MAX_LENGTH], ch;
    char *pend = sentence;

    printf("Please enter a sentence below: \n");
    while (pend < sentence + MAX_LENGTH && (ch = getchar()) != '\n')
    {
        *pend++ = ch;
    }

    printf("Reversed sentence: \n");
    while (pend > sentence)
    {
        printf("%c", *--pend);
    }
    printf("\n");

    return 0;
}
