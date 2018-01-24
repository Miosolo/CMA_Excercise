#include <stdio.h>

int main(void)
{
    int amt;
    while (1)
    {
        printf("Enter the amount of pics: ");
        scanf("%d", &amt);

        if (amt >= 1 && amt <= 100)
            break;
        else
            printf("The amount is out of range, please try again.\n");
    }

    int num1 = 400, num2 = 1, ch = 'A';
    for (int i = 0; i < amt; i++)
    {
        printf("http://www.pics.com/img/%c%.4d/%.3d.jpg\n", ch, num1, num2);
        ch++, num1 -= 2, num2++;
        if (ch == 'Z' + 1)
            ch = 'A';
    }

    return 0;
}