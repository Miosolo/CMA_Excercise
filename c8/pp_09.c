// random footprints

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define TOTAL_STEP 26
#define LENGTH 10
#define ERROR_LIMIT 1000

int main (void)
{
	//initialize
	char field[LENGTH][LENGTH];
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
			field[i][j] = '.';
	}
	char print = 'A';
	srand((unsigned) time(NULL));

	//footprints
	int x_position = 0, y_position = 0;
	field[0][0] = print;

	int direction[TOTAL_STEP] = {0};
	for (int i = 0; i < TOTAL_STEP - 1; i++)
	{
		int error_counter = 0;

		re_direct:
		direction[i] = (int) rand() % 4;
		switch (direction[i])
		{
			case LEFT:	x_position--;	break;
			case RIGHT:	x_position++;	break;
			case UP:	y_position--;	break;
			case DOWN:	y_position++; break;
		}

		//if走出不来
		if (error_counter > ERROR_LIMIT)
			break;

		//防止走重 & 溢出
		if (field[y_position][x_position] != '.' || x_position < 0 || x_position >= LENGTH || y_position < 0 || y_position >= LENGTH)
		{
			switch (direction[i])
			{
				case LEFT:	x_position++;	break;
				case RIGHT:	x_position--;	break;
				case UP:	y_position++;	break;
				case DOWN:	y_position--; break;
			}
			error_counter++;
			goto re_direct;
		}

		field[y_position][x_position] = ++print;
	}

	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
			printf("%c ", field[i][j]);
		printf("\n");
	}

	return 0;
}
