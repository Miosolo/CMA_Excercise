//find the smallest & largest words

#include <stdio.h>
#include <string.h>

#define END_LENGTH 4
#define MAX_LENGTH 20

void max_min_string(char *str, char *minstr, char *maxstr);

int main(void)
{
    char word[MAX_LENGTH], minstr[MAX_LENGTH], maxstr[MAX_LENGTH];

    for (int i = 0; ; i++)
    {
        printf("Please input a word(enter a 4-character word to stop): ");
        gets(word);

        if ((int)(strlen(word)) == END_LENGTH)
            break;
        if (i == 0)
        {
            strcpy(maxstr, word);
            strcpy(minstr, word);
        }
        else
            max_min_string(word, minstr, maxstr);
    }

    printf("\nLargest word: %s\n", maxstr);
    printf("Smallest word: %s\n", minstr);

    return 0;
}

void max_min_string(char *str, char *minstr, char *maxstr)
{
    if (strcmp(str, maxstr) > 0)
        strcpy(maxstr, str);
    if (strcmp(str, minstr) < 0)
        strcpy(minstr, str);

    return;
}