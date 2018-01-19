#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200

int main(void)
{
    int counter = 0;
    char sentence[MAX_LENGTH] = {0};

    printf("Please enter a sentence below:\n");
    fgets(sentence, MAX_LENGTH, stdin);

    char *p = sentence;
    while (*(p++))
    {
        if (*p == ' ' || *p == '\n')
            counter++;
    }

    printf("The sentence has %d words.", counter);

    return 0;
}
