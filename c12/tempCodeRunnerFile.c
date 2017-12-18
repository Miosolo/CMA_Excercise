// reverse a sentence (using pointer)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 200

char contents[STACK_SIZE];

void make_empty(int *top);
bool is_empty(int top);
bool is_full(int top);
void push(char ch, int *top);
char pop(int *top);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    int top = 0;
    char ch;

    printf("Please input a sentence below:\n");
    while ((ch = getchar()) != '\n' && (!is_full(top)))
    {
        push(ch, &top);
    }

    int valid_length = top;
    printf("Reversed sentence:\n");
    for (int i = 0; i < valid_length; i++)
    {
        printf("%c", pop(&top));
    }
    printf("\n");

    return 0;
}

void make_empty(int *top)
{
    *top = 0;
}

bool is_empty(int top)
{
    return top == 0;
}

bool is_full(int top)
{
    return top == STACK_SIZE;
}

void push(char ch, int *top)
{
    if (is_full(*top))
        stack_overflow();
    else
        contents[(*top)++] = ch;
}

char pop(int *top)
{
    if (is_empty(*top))
        stack_underflow();
    else
        return contents[--(*top)];

    return '\0';
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}
