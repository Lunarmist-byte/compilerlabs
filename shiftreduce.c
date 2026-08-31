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
    /* E -> id */
    if (top >= 1 && stack[top-1] == 'i' && stack[top] == 'd')
    {
        top--;
        stack[top] = 'E';
        stack[top+1] = '\0';
        printf("$%-15s %-15s Reduce E->id\n", stack, input+i);
    }

    /* E -> (E) */
    else if (top >= 2 &&
             stack[top-2] == '(' &&
             stack[top-1] == 'E' &&
             stack[top] == ')')
    {
        top -= 2;
        stack[top] = 'E';
        stack[top+1] = '\0';
        printf("$%-15s %-15s Reduce E->(E)\n", stack, input+i);
    }
}

void reduce_op()
{
    /* E -> E*E */
    if (top >= 2 &&
        stack[top-2] == 'E' &&
        stack[top-1] == '*' &&
        stack[top] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        stack[top+1] = '\0';
        printf("$%-15s %-15s Reduce E->E*E\n",
               stack, input+i);
    }

    /* E -> E+E */
    else if (top >= 2 &&
             stack[top-2] == 'E' &&
             stack[top-1] == '+' &&
             stack[top] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        stack[top+1] = '\0';
        printf("$%-15s %-15s Reduce E->E+E\n",
               stack, input+i);
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
        /* Reduce id and (E) */
        reduce();

        /* If stack has E+E and next input is *, shift */
        if (top >= 2 &&
            stack[top-2] == 'E' &&
            stack[top-1] == '+' &&
            stack[top] == 'E' &&
            input[i] == '*')
        {
            push(input[i++]);
            printf("$%-15s %-15s Shift\n",
                   stack, input+i);
        }

        /* If stack has E*E, reduce */
        else if (top >= 2 &&
                 stack[top-2] == 'E' &&
                 stack[top-1] == '*' &&
                 stack[top] == 'E')
        {
            reduce_op();
        }

        else
        {
            push(input[i++]);
            printf("$%-15s %-15s Shift\n",
                   stack, input+i);
        }
    }

    reduce();
    reduce_op();

    if (top == 0 && stack[0] == 'E')
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}
