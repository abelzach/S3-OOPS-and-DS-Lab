#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int max=10,top=-1,a[100];
char b[100];
void push(int ele)
{
    if(top==max-1)
    {
        printf("\n Stack is full");
    }
    else
    {
        top++;
        a[top]=ele;
    }
}
int pop()
{
    int n;
    if(top==-1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        n=a[top];
        top--;
        return n;
    }
}
void eval(char str[])
{
    int arr[100],k=0,A,B;
    for(int i=0;str[i]!='\0';i++)
    {
        if(isalpha(str[i]))
        {
            printf("\n Enter value for expression %c: ",str[i]);
            scanf("%d",&arr[k]);
            push(arr[k]);
        }
        else
        {
            switch(str[i])
            {
                case '+':A=pop();
                         B=pop();
                         push((A+B));
                         break;
                case '-':A=pop();
                         B=pop();
                         push((B-A));
                         break;
                case '*':A=pop();
                         B=pop();
                         push((A*B));
                         break;
                case '/':A=pop();
                         B=pop();
                         push((B/A));
                         break;
            }
        }
    }
    printf("\n Value after evaluation: %d\n",pop());
}
void pushc(char s)
{
        top++;
        b[top]=s;
}
char popc()
{
    char str;
    if(top==-1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        str=b[top];
        top--;
        return str;
    }
}

void convexp()
{
    int k=0,c;
    char str[100],result[100],temp;
    printf("\nEnter the infix expression: ");
    scanf("%s",str);
    pushc('(');
	strcat(str,")");
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')
        {
            pushc(str[i]);
        }
        else if(isalpha(str[i]))
        {
            result[k++]=str[i];
        }
        else if(str[i]=='+'||str[i]=='-')
        {
            if(top==-1)
            {
                pushc(str[i]);
            }
            else{
            for(int j=top;j>=0;j--){
            if(b[top]=='+'||b[top]=='-')
            {
                temp=popc();
                result[k++]=temp;
            }
            else if(b[top]=='*'||b[top]=='/')
            {
                temp=popc();
                result[k++]=temp;
            }
            else
            {
                pushc(str[i]);
                break;
            }
            }
        }
        }
        else if(str[i]=='*'||str[i]=='/')
        {
            if(top==-1)
            {
                pushc(str[i]);
            }
            else{
            temp=popc();
            if(temp=='+'||temp=='-')
            {
                pushc(temp);
                pushc(str[i]);
            }
            else if(temp=='*'||temp=='/')
            {
                result[k++]=temp;
                pushc(str[i]);
            }
            else
            {
                pushc(temp);
                pushc(str[i]);
            }
        }
        }
        else
        {
            temp=popc();
            while(temp!='(')
            {
                result[k++]=temp;
                temp=popc();
            }
        }

    }
    printf("The converted Postfix expression: %s\n",result);
    printf("do you want to input values for expression,(Y-1,N-0)\n");
    scanf("%d",&c);
    if(c==1)
    eval(result);
    else
    return;

}
void main()
{
    int choice,n;
    int ans;
    char str[100];
    do{
        top=-1;
    printf("\n*** MENU***\n");
    printf("1.Infix to postfix coversion\n");
    printf("2.Postfix evaluation\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: top=-1;
                convexp();
                break;
        case 2: top=-1;
                printf("Enter the expression:\n ");
                scanf("%s",str);
                eval(str);
                break;
        default:printf("Invalid option\n");
    }
    printf("\nDo you want to continue(Y-1,N-0):\n ");
    scanf("%d",&ans);
    }while(ans==1);
}
