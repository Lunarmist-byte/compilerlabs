#include <stdio.h>
#include <string.h>

char stack[100];
char input[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void reduce()
{
    int changed;

    do
    {
        changed = 0;

        /* i -> E */
        if (top >= 0 && stack[top] == 'i')
        {
            stack[top] = 'E';
            changed = 1;
        }

        /* (E) -> E */
        if (top >= 2 &&
            stack[top] == ')' &&
            stack[top - 1] == 'E' &&
            stack[top - 2] == '(')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }

        /* E op E -> E */
        if (top >= 2 &&
            stack[top] == 'E' &&
            stack[top - 2] == 'E' &&
            (stack[top - 1] == '+' ||
             stack[top - 1] == '-' ||
             stack[top - 1] == '*' ||
             stack[top - 1] == '/' ||
             stack[top - 1] == '^'))
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }

    } while (changed);
}

int main()
{
    int i = 0;

    printf("Enter expression ending with $: ");
    scanf("%s", input);

    push('$');

    printf("\n%-20s %-20s\n", "STACK", "INPUT");

    while (1)
    {
        printf("%-20s %-20s\n", stack, input + i);

        if (stack[top] == '$' && input[i] == '$')
            break;

        if (input[i] == '$')
        {
            reduce();
            if (stack[top] == 'E')
                break;
            else
            {
                printf("\nString is NOT Accepted\n");
                return 0;
            }
        }

        push(input[i]);
        i++;

        reduce();
    }

    if (top == 1 && stack[0] == '$' && stack[1] == 'E')
        printf("\nString is Accepted\n");
    else
        printf("\nString is NOT Accepted\n");

    return 0;
}
