#include <stdio.h>
#include <string.h>

char s[100];
int top;

void Init()
{
    top = -1;
}

int Full()
{
    if(top==100) return 1;
    return 0;
}

int Empty()
{
    if(top==-1) return 1;
    return 0;
}

void Push(char c)
{
    if(Full()==0) s[++top] = c;
}

char Pop()
{
    if(Empty()==0) return s[top--];
}

int Priority(char c)
{
    if(c=='*'||c=='/') return 2;
    return 1;
}

void main()
{
    char string[100],c;
    printf("Enter the expression :: ");
    scanf(" %[^\n]",string);

    char postfix[100];
    int j=0;
    Init();

    for(int i=0;i<strlen(string);i++)
    {
        if(string[i] >= '0' && string[i] <= '9') postfix[j++] = string[i];
        else if(string[i]=='(') Push(string[i]);
        else if(string[i]==')')
        {
            while(s[top]!='(') postfix[j++] = Pop();
            Pop();
        }

        else
        {
            if(Empty()==1)
            {
                Push(string[i]);
            }
            else
            {
                while(Priority(string[i])<Priority(s[top]))
                    postfix[j++] = Pop();
                Push(string[i]);
            }
        }
    }
    while(Empty()==0) postfix[j++] = Pop();
    printf("Postfix expression:  ");
    for(int i=0;i<j;i++) printf("%c",postfix[i]);
}
