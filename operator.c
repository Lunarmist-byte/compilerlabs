#include <stdio.h>
#include <string.h>

char stack[100];
char input[100];
int top = -1;

void push(char c)
{
    top++;
    stack[top] = c;
    stack[top + 1] = '\0';
}

void reduce()
{
    int changed = 1;

    while (changed)
    {
        changed = 0;

        if (top >= 1 &&
            stack[top - 1] == 'i' &&
            stack[top] == 'd')
        {
            top--;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }

        else if (top >= 2 &&
                 stack[top - 2] == '(' &&
                 stack[top - 1] == 'E' &&
                 stack[top] == ')')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }

        else if (top >= 2 &&
                 stack[top - 2] == 'E' &&
                 stack[top - 1] == '+' &&
                 stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }

        else if (top >= 2 &&
                 stack[top - 2] == 'E' &&
                 stack[top - 1] == '-' &&
                 stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }

        else if (top >= 2 &&
                 stack[top - 2] == 'E' &&
                 stack[top - 1] == '*' &&
                 stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }

        else if (top >= 2 &&
                 stack[top - 2] == 'E' &&
                 stack[top - 1] == '/' &&
                 stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }

        else if (top >= 2 &&
                 stack[top - 2] == 'E' &&
                 stack[top - 1] == '^' &&
                 stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            changed = 1;
        }
    }
}

int main()
{
    int i = 0;

    printf("Enter expression ending with $: ");
    scanf("%99s", input);

    push('$');

    printf("\n%-20s %-20s\n", "STACK", "INPUT");

    while (1)
    {
        printf("%-20s %-20s\n", stack, input + i);

        if (top == 1 &&
            stack[0] == '$' &&
            stack[1] == 'E' &&
            input[i] == '$')
        {
            printf("\nString is Accepted\n");
            break;
        }

        if (input[i] == '\0')
        {
            printf("\nString is NOT Accepted\n");
            break;
        }

        push(input[i]);
        i++;

        reduce();
    }

    return 0;
}
