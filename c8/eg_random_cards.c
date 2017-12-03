// Deals a random hand of cards.

#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main()
{
	bool card_occurance[NUM_RANKS][NUM_SUITS] = {{false}};
	int cards = 0;
	const char rank[ ] =
	{'a', '2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k'};
	const char suit[ ] = {'c', 'd', 'h', 's'};

	printf("Enter the number of cards in hand: ");
	scanf("%d", &cards);

	printf("Your hand: ");
	for(int r = 0, s = 0; cards > 0;)
	{
		srand((unsigned) time(NULL));
		r = (int) (rand() % 13);
		s = (int) (rand() % 4);
		if (card_occurance[r][s])
			continue;
		card_occurance[r][s] = true;
		printf("%c%c\t", suit[s], rank[r]);
		cards--;
	}

return 0;
}
