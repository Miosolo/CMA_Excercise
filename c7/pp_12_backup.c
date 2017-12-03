//to simulate a simple calculator
#include <stdio.h>

int main()
{
	char key;
	float cur, next;

	printf("Enter an expression:\n");
	scanf("%f", &cur);

	for(; key != '\n'; )
	{
		scanf("%c", &key);
		switch (key)
		{
			case '+':	scanf("%f", &next);	cur += next;	break;
			case '-':	scanf("%f", &next);	cur -= next;	break;
			case '*':	scanf("%f", &next);	cur *= next;	break;
			case '/':	scanf("%f", &next);	cur /= next;	break;
			//default:	printf("Error: unspported symbol\n");	break;
		}
	}

	printf("Value of expression: %f\n", cur);

	return 0;
}
