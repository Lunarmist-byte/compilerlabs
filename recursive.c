#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];
int i=0;
void E();
void Eprime();
void T();
void Tprime();
void F();

void E(){
    T();
    Eprime();
}
void Eprime()
{
    if(input[i]=='+')
    {
        i++;
        T();
        Eprime();
    }
}
void T()
{
    F();
    Tprime();
}
void Tprime(){
    if(input[i]=='*')
    {
        i++;
        F();
        Tprime();
    }
}
void F(){
    if(input[i]=='('){
        i++;
        E();
        if(input[i]==')')
            i++;
        else
        {
            printf("Invalid Expression\n");
            exit(0);
        }
    }
    else if((input[i]>='a'&&input[i]<='z')||
            (input[i]>='A'&&input[i]<='Z'))
    {
        i++;
    }
    else
    {
        printf("Invalid Expression\n");
        exit(0);
    }
    }

    int main()
    {
        printf("Enter the expression:");
        scanf("%s",input);

        E();

        if(input[i]=='\0')
            printf("Valid Expression\n");
        else
            printf("Invalid Expression\n");

        return 0;
    }
