// test anagrams

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define LENGTH 30

bool repeat(char word_1[], char word_2[], int length);

int main(void)
{
	char word_1[LENGTH], word_2[LENGTH];
	int length_1 = 0, length_2 = 0;
	bool bool_anagram;

	printf("Enter first word: ");
	for(int i = 0; i < LENGTH; i++)
	{
		word_1[i] = tolower(getchar());
		length_1++;
		if(word_1[i] == '\n')
		{
			word_1[i] = '\x0';
			length_1--;
			goto loop_off_1;
		}
	}
	loop_off_1:

	printf("Enter second word: ");
	for(int i = 0; i < LENGTH; i++)
	{
		word_2[i] = tolower(getchar());
		length_2++;
		if(word_2[i] == '\n')
		{
			word_2[i] = '\x0';
			length_2--;
			goto loop_off_2;
		}
	}
	loop_off_2:

	if(length_1 - length_2)
		bool_anagram = false;
	else
		bool_anagram = repeat(word_1, word_2, length_1);

	if(bool_anagram)
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");

	return 0;
}

bool repeat(char word_1[], char word_2[], int length)
{
	char repeat_1[26] = {0}, repeat_2[26] = {0};

	for(int i = 0; i < length; i++)
	{
		repeat_1[(int)(word_1[i] - 'a')]++;
		repeat_2[(int)(word_2[i] - 'a')]++;
	}

	for(int i = 0; i < 26; i++)
	{
		if(repeat_1[i] - repeat_2[i])
			return false;
	}
	return true;
}
