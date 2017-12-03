// Beaufort scale (simplified)

# include <stdio.h>

int main()
{
	int speed;

	printf("Enter the speed of wind in integer (mph): ");
	scanf("%d", &speed);

	if (speed == 0)
	printf("Calm\n");
	else if (speed <= 3)
	printf("Light air\n");
	else if (speed <= 27)
	printf("Breeze\n");
	else if (speed <= 47)
	printf("Gale\n");
	else if (speed <= 63)
	printf("Storm\n");
	else if (speed > 63)
	printf("Hurricane\n");
	else
	printf("Invalid number\n");

	return 0;
}
