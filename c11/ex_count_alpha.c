#include <stdio.h>
#include <ctype.h>

#define LENGTH 20

int count_alpha(char []);

int main(void)
{
    char ch[LENGTH];
    gets(ch);

    for (int i = 0; i < LENGTH; i++)
        printf("%c", ch[i]);

    printf("\n%d", count_alpha(ch));

    return 0;
}

int count_alpha(char ch[])
{
    int alpha_amount = 0;

    for (int i = 0; i < LENGTH; i++)
    {
        if (isalpha(ch[i]))
            alpha_amount++;
    }

    return alpha_amount;
}
