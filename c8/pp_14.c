//reverse the words
#include <stdio.h>
#define LENGTH 200

void reverse(char [], char);

int main(void)
{
	char sentence[LENGTH], endchar;

	printf("Enter a sentence: ");
	for(int i = 0; i < LENGTH ; i++)
	{
		sentence[i] = getchar();
		if(sentence[i] == '\n')
		{
			sentence[i] = '\0';
			endchar = sentence[i - 1];
			sentence[i - 1] = '\0';
			goto start_reverse;
		}
	}

	start_reverse:
	reverse(sentence, endchar);

	return 0;
}

void reverse(char sentence[LENGTH], char endchar)
{
	char rev_sentence[LENGTH];
	int rev_counter = 0;

	for(int i = LENGTH - 1; i >= 0; i--)
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
	}

	for(int i = 0; i < rev_counter; i++)
		printf("%c", rev_sentence[i]);
	printf("%c\n", endchar);
}
