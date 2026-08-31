#include <stdio.h>
#include <string.h>

char stack[100], input[100];
int top = -1, i = 0;

void push(char c)
{
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void reduce()
{
    int reduced = 1;

    while (reduced)
    {
        reduced = 0;

        /* E -> id */
        if (top >= 1 && stack[top - 1] == 'i' && stack[top] == 'd')
        {
            top--;
            stack[top] = 'E';
            stack[top + 1] = '\0';

            printf("$%-15s %-15s %-10s\n",
                   stack, input + i, "Reduce E->id");

            reduced = 1;
        }

        /* E -> (E) */
        else if (top >= 2 &&
                 stack[top - 2] == '(' &&
                 stack[top - 1] == 'E' &&
                 stack[top] == ')')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';

            printf("$%-15s %-15s %-10s\n",
                   stack, input + i, "Reduce E->(E)");

            reduced = 1;
        }

        /* E -> E*E  (higher precedence) */
        else if (top >= 2 &&
                 stack[top - 2] == 'E' &&
                 stack[top - 1] == '*' &&
                 stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';

            printf("$%-15s %-15s %-10s\n",
                   stack, input + i, "Reduce E->E*E");

            reduced = 1;
        }

        /* E -> E+E */
        else if (top >= 2 &&
                 stack[top - 2] == 'E' &&
                 stack[top - 1] == '+' &&
                 stack[top] == 'E')
        {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';

            printf("$%-15s %-15s %-10s\n",
                   stack, input + i, "Reduce E->E+E");

            reduced = 1;
        }
    }
}

int main()
{
    printf("Enter the expression: ");
    scanf("%s", input);

    printf("\nStack           Input           Action\n");
    printf("-----------------------------------------------\n");

    while (input[i] != '\0')
    {
        push(input[i]);
        i++;

        printf("$%-15s %-15s %-10s\n",
               stack, input + i, "Shift");

        reduce();
    }

    reduce();

    if (top == 0 && stack[0] == 'E')
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}
