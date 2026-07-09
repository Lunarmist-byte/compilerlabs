#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char str[]){
    char keywords[][10]={
        "int","char","float","if","else","while","for","return","void","break","continue"
        };
    int n=sizeof(keywords)/sizeof(keywords[0]);
    for(int i=0;i<n;i++){
        if(strcmp(str,keywords[i])==0)
            return 1;

    }
    return 0;
}
int main()
{
    FILE *fp;
    char ch,buffer[20];
    int i=0;
    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("File Not Found\n");
        return 0;
    }
    while((ch=fgetc(fp))!=EOF){
        if(ch=='/'){
            char next=fgetc(fp);
            if(next=='/'){
                while((ch=fgetc(fp))!='\n'&&ch!=EOF);
                    continue;
            }
            else if(next=='*'){
                char prev=' ';
                while((ch=fgetc(fp))!=EOF){
                    if(prev=='*'&&ch=='/')
                        break;
                    prev=ch;
                }
                continue;
            }
            else {
                printf("/ --> Operator\n");
                fseek(fp,-1,SEEK_CUR);
                continue;
            }
        }
        if(isalpha(ch)){
            buffer[i++]=ch;
            while((ch=fgetc(fp))!=EOF&&(isalnum(ch)))
            {
                buffer[i++]=ch;
            }
            buffer[i]='\0';
            i=0;
            if(isKeyword(buffer))
                printf("%s -->Keyword\n",buffer);
            else
                printf("%s -->Identifier\n",buffer);
            if(ch==EOF)
                break;
        }
        if(isdigit(ch)){
            while((ch=fgetc(fp))!=EOF &&isdigit(ch));
            printf("Number --> Constant\n");
            if(ch!=EOF)
                fseek(fp,-1,SEEK_CUR);
            continue;
        }
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='<'||ch=='>'||ch=='%')
        {
          printf("%c -->Operator\n",ch);
        }
        if(ch=='('||ch==')'||ch=='{'||ch=='}'||ch==';'||ch==','){
          printf("%c -->Special Symbol\n",ch);

        }
    }
    fclose(fp);
    return 0;
}
