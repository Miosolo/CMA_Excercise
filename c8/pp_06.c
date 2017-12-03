// B1FF Style converter

#include <stdio.h>
#include <ctype.h>
#define LENGTH 100

int main ()
{
	char message[LENGTH];
	int i;

	printf("Enter message: ");
	for (i = 0; i < LENGTH; i++)
	{
		message[i] = getchar();
		if (message[i] != '\n')
			continue;
		message[i] = '\x0';
		break;
	}

	for (i = 0; message[i] != '\x0'; i++)
	{
		message[i] = toupper (message[i]);
		switch (message[i])
		{
			case 'A':	message[i] = '4';	break;
			case 'B':	message[i] = '8';	break;
			case 'E':	message[i] = '3';	break;
			case 'I':	message[i] = '1';	break;
			case 'O':	message[i] = '0';	break;
			case 'S':	message[i] = '5';	break;
		}
	}
	for (int j = 0; j < 10; j++)
	{
		message[i] = '!';
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		printf("%c", message[j]);
	}
	printf("\n");

	return 0;
}
