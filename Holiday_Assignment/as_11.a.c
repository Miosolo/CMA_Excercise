//约瑟夫问题的模拟解
#include <stdio.h>
#define ALIVE 1
#define DEAD 0

int main(void)
{
    int m, n, josephus = 0;

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    int people[n], cycle, *p = people;
    for (int i = 0; i < n; i++)
    {
        people[i] = ALIVE;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cycle = m;
        while (cycle != 0)
        {
            if (p < people + n && *p == DEAD)
            {
                p++;
            }
            else if (p < people + n && *p == ALIVE)
            {
                cycle--;
                p++;
            }
            else
            {
                p = people;
            }
        }

        *(p - 1) = DEAD;
    }

    for (int i = 0; i < n; i++)
    {
        if (people[i] == DEAD)
            ;
        else
        {
            josephus = i;
            goto loopDone;
        }
    }

loopDone:
    printf("The %dth person survived.\n", josephus + 1);

    return 0;
}