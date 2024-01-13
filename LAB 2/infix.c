#include<stdio.h>
#include<stdlib.h>
char stack[50];
int top=-1;
void push(char ele)
{
    top++;
    stack[top]=ele;
}
char pop()
{
    return stack[top--];
}
int pr(char sym)
{
    if(sym=='^'){
        return 3;
    }
    else if(sym=='*'||sym=='/')
    {
        return 2;
    }
    else if(sym=='+'||sym=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char infix[50],postfix[50],n,x,ch;
    printf("Enter the infix expression:\n");
    scanf("%s",infix);
    printf("Entered expression is: %s\n",infix);
    push('#');
    push('(');
    int k=0,i=0;
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }

        else if(isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch==')')
        {
            while(ch!='(')
            {
                n=pop();
                postfix[k++]=n;
            }
            x=pop();
        }
        else
        {
            while(pr(stack[top])>pr(ch))
            {
                postfix[k++]=pop();
            }
            push(ch);
        }

    }
    while(stack[top]!='#')
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("Postfix expression is:%s",postfix);
    return 0;
}
