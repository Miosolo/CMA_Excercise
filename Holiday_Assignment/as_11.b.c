//约瑟夫问题的数学解
#include <stdio.h>

int main(void)
{
    int m, n, josephus;

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    josephus = 0;
    for (int i = 1; i < n; i++)
    {
        josephus = (josephus + m) % (i + 1);
    }

    printf("The %dth person survived.\n", josephus + 1);

    return 0;
}