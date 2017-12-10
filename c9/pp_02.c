// random footprints

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define TOTAL_STEP 26
#define LENGTH 10
#define BLANK '.'

char field[LENGTH + 2][LENGTH + 2];
static int direction[TOTAL_STEP] = {0};

bool overflow(int rank, int file);
bool dead(int rank, int file);
bool overlap(int rank, int file);
bool random_walk(void);
void generate_field(void);
void print_field(void);
void random_direction(int step, int *prank, int *pfile);
void restore_step(int step, int *prank, int *pfile);

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

bool random_walk(void)
{
    //initialize (field is 2 ranks & 2 files larger than needed)
    char letter = 'A';
    int file = 1, rank = 1, step = 0;
    srand((unsigned) time(NULL));
 
    //build the trace
	field[1][1] = letter;
	for (step = 0; step < TOTAL_STEP - 1; step++)
	{
        random_step:
        random_direction(step, &rank, &file);

        if (overflow(rank, file) || overlap(rank, file))
            {
            restore_step(step, &rank, &file);
            goto random_step;
            }
        else if (step != TOTAL_STEP - 1 && dead(rank, file))
            {
                field[rank][file] = ++letter;           
                return false;
            }

        else 
            {
                field[rank][file] = ++letter;
            }
	}

    return true;
}

void random_direction(int step, int *prank, int *pfile)
{
    direction[step] = (int) rand() % 4;
    switch (direction[step])
    {
        case LEFT:	(*pfile)--; break;
        case RIGHT:	(*pfile)++;	break;
        case UP:	(*prank)--; break;
        case DOWN:	(*prank)++; break;
    }

    return;
}

void restore_step(int step, int *prank, int *pfile)
{
    switch (direction[step])
    {
        case LEFT:	(*pfile)++;	break;
        case RIGHT:	(*pfile)--;	break;
        case UP:	(*prank)++;	break;
        case DOWN:	(*prank)--; break;
    }

    return;
}

bool overflow(int rank, int file)
{
    if (rank  == 0 || rank == LENGTH + 1 || file == 0 || file == LENGTH + 1)
        return true;

    return false;
}

bool overlap(int rank, int file)
{
    if (field[rank][file] != BLANK)
        return true;

    return false;
}

bool dead(int rank, int file)
{
    int dead_end = 0;

    if (overflow(rank - 1, file) || overlap(rank - 1, file))
        dead_end++;
    if (overflow(rank + 1, file) || overlap(rank + 1, file))
        dead_end++;
    if (overflow(rank, file - 1) || overlap(rank, file - 1))
        dead_end++;
    if (overflow(rank, file + 1) || overlap(rank, file + 1))
        dead_end++;

    if (dead_end == 4)
        return true;

    return false;
}