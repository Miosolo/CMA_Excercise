#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPlanet(char *planet)
{
    char *planetList[] = {"Mercury",
                          "Venus",
                          "Earth",
                          "Mars",
                          "Jupiter",
                          "Saturn",
                          "Uranus",
                          "Neptune",
                          "Pluto",
                          NULL};
    for (char **p = planetList; *p != NULL; p++)
    {
        if (strcmp(planet, *p) == 0)
            return true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {

        if (isPlanet("Her"))
            printf("is a planet.\n");
        else
            printf("is not a planet.\n");

        printf("Please enter a planet at least.\n");
        return 0;
    }
    else
    {
        for (char **planet = argv + 1; *planet != NULL; planet++)
        {
            if (isPlanet(*planet))
                printf("%s is a planet.\n", *planet);
            else
                printf("%s is not a planet.\n", *planet);
        }
    }

    return 0;
}