#include <stdio.h>

#define MAX_LENGTH 200

int main (void)
{
    char sentence[MAX_LENGTH], ch;
    int end;

    printf("Please enter a sentence below: \n");
    for (end = 0; end < MAX_LENGTH && (ch = getchar()) != '\n'; end++)
    {
        sentence[end] = ch;
    }

    printf("Reversed sentence: \n");
    for (end--; end >= 0; end--)
    {
        printf("%c", sentence[end]);
    }
    printf("\n");

    return 0;
}