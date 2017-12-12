//运用stack检查括号是否嵌套正确

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 30

char symbols[STACK_SIZE];
int top = 0;

bool this_match(char input);
bool nest(void);
void push(char input);
char pop(void);

int main(void)
{
    printf("Enter parenteses and/or braces: ");

    if (nest())
        printf("Parenteses/braces are properly nested.\n");
    else
        printf("Parenteses/braces are not properly nested.\n");

    return 0;
}

bool nest(void)
{
    bool all_match = false;
    char current;

    while(1)
    {
        current = getchar();

        if (current == '{' || current == '(')
        {
            push(current);
        }
        else if (current == '}' || current == ')')
        {
            if (this_match(current))
                {
                    if (top == 1)
                    {
                        all_match = true;
                        goto whether_nest;
                    }
                    else
                        pop();
                }
            else
                goto whether_nest;
        }
        else if (current == '\n')
            break;
    }

    whether_nest:
        return all_match;
}

bool this_match(char input)
{
    if (input == '}')
    {
        if (pop() == '{')
        {
            push('{');
            return true;
        }
        else
            return false;
    }
    else
    {
        if (pop() == '(')
        {
            push('(');
            return true;
        }
        else
            return false;
    }
}

void push(char input)
{
    symbols[top++] = input;
    return;
}

char pop(void)
{
    return symbols[--top];
}