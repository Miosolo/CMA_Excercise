// random footprints
#include "randomWalk.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_field(void);
void print_field(void);

int main(void)
{
	//initialize
    generate_field();

    bool finish = random_walk();
    
    if (finish)
    {
        printf("Random trace (finished): \n\n");
        print_field();
    }
    else
    {
        printf("Random trace (unfinished): \n\n");
        print_field();
    }

    system("pause");
    return 0;
}

void generate_field(void)
{
    for (int i = 1; i <= LENGTH; i++)
	{
		for (int j = 1; j <= LENGTH; j++)
			field[i][j] = BLANK;
	}

    return;
}

void print_field(void)
{
    for (int i = 1; i <= LENGTH; i++)
	{
		for (int j = 1; j <= LENGTH; j++)
			printf("%c ", field[i][j]);
		printf("\n");
	}

    return;
}

