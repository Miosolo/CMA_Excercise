#include <stdio.h>

int main(void)
{
    char ch[200];

    gets(ch);
    printf("%s", ch);

    return 0;
}