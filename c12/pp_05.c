//reverse the words (using pointer), suppose there are only spaces between words.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LENGTH 1000

void reverse(char [], char);

int main(void)
{
    char sentence[LENGTH + 1], endchar, *pletter = sentence;

    printf("Enter a sentence: ");
    gets(sentence);

    while (*pletter++)
        ;
    endchar = *--pletter--; //*pletter is now pointing at the last letter

    char rev_sentence[LENGTH + 1], *prev = rev_sentence;
    int word_length = 0;
    /*for(int i = LENGTH - 1; i >= 0; i--)
	{
		if(sentence[i] == ' ')
		{
			for(int j = i + 1; sentence[j] != ' ' && sentence[j] != '\0'; j++)
			{
				rev_sentence[rev_counter++] = sentence[j];
			}
			rev_sentence[rev_counter++] = ' ';
		}
		else if(i == 0)
		{
			for(int j = 0; sentence[j] != ' ' && sentence[j] != '\0'; j++)
			{
				rev_sentence[rev_counter++] = sentence[j];
			}
		}
	}*/

    while (pletter >= sentence)
    {
        while (isalpha(*pletter--))
        {
            word_length++;
        }
    }

	printf("%s%c\n", rev_sentence, endchar);

	return 0;
}
