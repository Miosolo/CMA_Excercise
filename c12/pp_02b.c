// estimate palindrome

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main(void)
{
    char sentence[MAX_LENGTH + 1], *left = sentence, *right = sentence;
    bool palindrome = true;

    printf("Please enter a sentence below:\n");
    gets(sentence);

    while (*right++);
    right -= 2; //point to the last letter

    while (left <= right && palindrome)
    {
        while (!isalpha(*left))
            left++;
        while (!isalpha(*right))
            right--;
        if (tolower(*left) == tolower(*right))
        {
            left++;
            right--;
        }
        else
        {
            palindrome = false;
        }
    }

    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}