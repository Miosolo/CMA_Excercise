// reverse a sentence

#include <stdio.h>

#define MAX_LENGTH 300

char sentence[MAX_LENGTH];
int top;

void input(void);
void reverse_print(void);
void push(char ch);
char pop(void);

int main(void)
{
    input();
    reverse_print();

    return 0;
}

void input(void)
{
    char temp;
    top = -1;

    printf("Please enter a sentence below.\n");

    while ((temp = getchar()) != '\n' && top < MAX_LENGTH)
    {
        push(temp);
    }

    return;
}

void reverse_print(void)
{
    printf("Reversed sentence:\n");
    for (; top >= 0; )
    {
        printf("%c", pop());
    }
    printf("\n");

    return;
}

void push(char ch)
{
    sentence[++top] = ch;

    return;
}

char pop(void)
{
    return sentence[top--];
}