#include <stdio.h>
#include <string.h>
#define MAX 20
typedef struct{
    int from;
    int to;
    char symbol;
}Transition;

Transition t[MAX];
int closure[MAX];
int count=0;

void epsilonClosure(int state,int n){
    int i;
    for(i=0;i<count;i++){
        if(closure[i]==state)
            return;

    }
    closure[count++]=state;
    for(i=0;i<n;i++){
        if(t[i].from==state && t[i].symbol=='e')
        {
            epsilonClosure(t[i].to,n);
        }
    }
}
int main(){
    int n,i,start;
    printf("Enter the no of transitions:");
    scanf("%d",&n);
    printf("Enter transitions(from to symbol:\n");
    for(i=0;i<n;i++){
        scanf("%d %d %c",&t[i].from,&t[i].to,&t[i].symbol);
    }
    printf("Enter the state:");
    scanf("%d",&start);
    epsilonClosure(start,n);
    printf("\nEpsilon Closure(%d)={ ",start);
    for(i=0;i<count;i++)
        printf("%d",closure[i]);
    printf("}\n");
    return 0;
}
