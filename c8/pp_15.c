//Caesar encryption
#include <stdio.h>
#define LENGTH 80

int main(void)
{
	char sentence[LENGTH], encrypt[LENGTH];
	int step;

	printf("Enter message to be encrypted: ");
	/*for(int i = 0; i < LENGTH; i++)
	{
		sentence[i] = getchar();
		if(sentence[i] == '\n')
		{
			sentence[i] = '\x0';
			goto loop_off;
		}
	}
	loop_off:*/

	for(int i = 0; i < LENGTH; i++)
	{
		scanf("%c", &sentence[i]);
	}
	

	printf("Enter shift amount(1 - 25): ");
	scanf("%d", &step);

	printf("Encrypted message: ");
	for(int i = 0; sentence[i] != '\x0'; i++)
	{
		if(sentence[i] >= 'a' && sentence[i] <= 'z')
		{
			encrypt[i] = (sentence[i] - 'a' + step) % 26 + 'a';
		}
		else if(sentence[i] >= 'A' && sentence[i] <= 'Z')
		{
			encrypt[i] = (sentence[i] - 'A' + step) % 26 + 'A';
		}
		else
		{
			encrypt[i] = sentence[i];
		}
		printf("%c", encrypt[i]);
	}
	printf("\n");

	return 0;
}
