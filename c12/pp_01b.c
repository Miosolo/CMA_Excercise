// reverse a sentence (using pointer)

#include <stdio.h>

#define MAX_LENGTH 300

char sentence[MAX_LENGTH];

void input(int *ptop);
void reverse_print(int *ptop);
void push(int *ptop, char ch);
char pop(int *ptop);

int main(void)
{
    int top;

    input(&top);
    reverse_print(&top);

    return 0;
}

void input(int *ptop)
{
    char temp;
    *ptop = -1;

    printf("Please enter a sentence below.\n");

    while ((temp = getchar()) != '\n' && *ptop < MAX_LENGTH)
    {
        push(ptop, temp);
    }

    return;
}

void reverse_print(int *ptop)
{
    printf("Reversed sentence:\n");
    for (; *ptop >= 0;)
    {
        printf("%c", pop(ptop));
    }
    printf("\n");

    return;
}

void push(int *ptop, char ch)
{
    sentence[++(*ptop)] = ch;

    return;
}

char pop(int *ptop)
{
    return sentence[(*ptop)--];
}