// estimate palindrome

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main(void)
{
    char sentence[MAX_LENGTH + 1];
    int left = 0, right = 0;
    bool palindrome = true;

    printf("Please enter a sentence below:\n");
    gets(sentence);

    while (sentence[right++]);
    right -= 2; //point to the last letter

    while (left <= right && palindrome)
    {
        while (!isalpha(sentence[left]))
            left++;
        while (!isalpha(sentence[right]))
            right--;
        if (tolower(sentence[left]) == tolower(sentence[right]))
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