// reverse a sentence (using pointer)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 200

char contents[STACK_SIZE];
int top = 0;
char *pcontents = contents;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char ch;

    printf("Please input a sentence below:\n");
    while ((ch = getchar()) != '\n' && (!is_full()))
    {
        push(ch);
    }

    int valid_length = top;
    printf("Reversed sentence:\n");
    for (int i = 0; i < valid_length; i++)
    {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        *(pcontents + top++) = ch;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return *(pcontents + --top);

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
