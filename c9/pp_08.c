// a simple rolling dice game

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);
bool play_again(void);

int main(void)
{
    int win = 0, loss = 0;
    srand((unsigned)time(NULL));

    do
    {
        printf("\n");
        if (play_game())
        {
            printf("\n");
            win++;
        }
        else
        {
            printf("\n");
            loss++;
        }
    } while (play_again());

    printf("\nWins: %d    Losses: %d\n", win, loss);

    return 0;
}

int roll_dice(void)
{
    return 2 + rand() % 6 + rand() % 6;
}

bool play_game(void)
{
    int target = roll_dice(), current_roll;

    if (target == 7 || target == 11)
    {
        printf("You rolled: %d\n", target);
        printf("You win!\n");
        return true;
    }
    else if (target == 2 || target == 3 || target == 12)
    {
        printf("You rolled: %d\n", target);
        printf("You lose!\n");
        return false;
    }
    else
    {
        printf("Your point is %d\n", target);
        while (1)
        {
            current_roll = roll_dice();
            printf("You rolled %d\n", current_roll);

            if (current_roll == target)
            {
                printf("You win!\n");
                return true;
            }
            else if (current_roll == 7)
            {
                printf("You lose!\n");
                return false;
            }
        }
    }
}

bool play_again(void)
{
    printf("Play agian? (Y/y for yes)  ");
    if (tolower(getchar()) == 'y')
    {
        fflush(stdin);
        return true;
    }

    fflush(stdin);
    return false;
}
