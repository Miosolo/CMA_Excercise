// rank the grade using switch function

# include <stdio.h>

int main()
{
	int grade, tens;

	printf("Enter numerical grade: ");
	scanf("%d", &grade);
	tens = grade / 10;

	if (grade > 100 || grade < 0)
	{
		printf("Error: invalid grade\n");
		goto done;
	}

	switch (tens)
	{
		case 10:	case 9 :	printf("Letter grade: A\n");	break;
		case 8 :	printf("Letter grade: B\n");	break;
		case 7 :	printf("Letter grade: C\n");	break;
		case 6 :	printf("Letter grade: D\n");	break;
		case 5 : case 4 : case 3 : case 2 : case 1 : case 0 :	printf("Letter grade: F\n");	break;
	}

	done:
	return 0;
}
