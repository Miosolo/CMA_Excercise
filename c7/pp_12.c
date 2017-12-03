//to simulate a simple calculator
#include <stdio.h>

int main()
{
	char key;
	float cur, next;

	printf("Enter an expression:\n");
	scanf("%f", &cur);
		for(; ; )
	{
		scanf("%c", &key);
		switch (key)
		{
			case '+':	scanf("%f", &next);	cur += next;	break;
			case '-':	scanf("%f", &next);	cur -= next;	break;
			case '*':	scanf("%f", &next);	cur *= next;	break;
			case '/':	scanf("%f", &next);	cur /= next;	break;
			case '\n': goto loop_done;
			default:
				printf("Error: unspported symbol.\n");
				return 0;
		}
	}

	loop_done:
	printf("Value of expression: %.3f\n", cur);

	return 0;
}
