#include <stdio.h>
#include <ctype.h>
#include <string.h>

char prec[9][9] = {
    /*        +    -    *    /    ^    (    )    id   $  */
    /* + */ {'>','>','<','<','<','<','>','<','>'},
    /* - */ {'>','>','<','<','<','<','>','<','>'},
    /* * */ {'>','>','>','>','<','<','>','<','>'},
    /* / */ {'>','>','>','>','<','<','>','<','>'},
    /* ^ */ {'>','>','>','>','<','<','>','<','>'},
    /* ( */ {'<','<','<','<','<','<','=','<',' '},
    /* ) */ {'>','>','>','>','>',' ','>',' ','>'},
    /*id */ {'>','>','>','>','>',' ','>',' ','>'},
    /* $ */ {'<','<','<','<','<','<',' ','<','$'}
};
char symbols[] = {'+','-','*','/','^','(',')','i','$'};

int index_of(char c) {
    int i;
    if (isalnum(c) && c != 'i') return 7;   /* any operand -> id */
    for (i = 0; i < 9; i++)
        if (symbols[i] == c) return i;
    return 7;
}

int main() {
    char stack[50], input[50];
    int top = 0, i = 0;

    printf("Enter input ending with $ (use i for id, e.g. i+i*i$): ");
    scanf("%s", input);

    stack[top] = '$'; stack[top+1] = '\0';

    printf("%-15s %-15s\n", "STACK", "INPUT");
    while (1) {
        printf("%-15s %-15s\n", stack, input + i);
        char s = stack[top], a = input[i];

        if (s == '$' && a == '$') {
            printf("String is Accepted\n");
            break;
        }

        char rel = prec[index_of(s)][index_of(a)];

        if (rel == '<' || rel == '=') {
            stack[++top] = a; stack[top+1] = '\0';
            i++;
        } else if (rel == '>') {
            while (top > 0 && prec[index_of(stack[top-1])][index_of(stack[top])] != '<')
                top--;
            top--;
            stack[top+1] = '\0';
        } else {
            printf("String is not Accepted — syntax error\n");
            break;
        }
    }
    return 0;
}
