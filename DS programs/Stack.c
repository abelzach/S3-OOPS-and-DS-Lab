#include<stdio.h>
#define max 5
int top=-1,stack[max];
void push()
{
    int value;
    if(top==max-1)
     {
         printf(" Stack is full");
     }
     else
     {
         printf(" Enter the value : ");
         scanf("%d",&value);
         top++;
         stack[top]=value;
     }
}
void pop()
{
    if(top==-1)
    {
        printf("\n The stack is empty");
    }
    else
    {
        printf("\n The deleted element is %d",stack[top]);
        top--;
    }
}
void isempty()
{
    if(top==-1)
        printf("\n The stack is empty");
    else
        printf("\n The stack is not empty");
}
void isfull()
{
    if(top>=max)
        printf("\n The stack is full");
    else
        printf("\n The stack is not full");
}
void peek()
{
    if(top==-1)
    {
    printf("\n The stack is empty");
    }
   else
    {
        printf("\n The element on top is %d", stack[top]);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\n The stack is empty");
    }
    else
    {
        printf("\n Stack is : \n");
        for(i=top; i>=0; i--)
        {
            printf(" %d\n",stack[i]);
        }
    }
}

void main()
{
    int ch;
    char c;
    printf("\n\t\t\tMENU");
    printf("\n 1.PUSH \n 2.POP \n 3.PEEK \n 4.IS EMPTY \n 5.IS FULL \n 6.DISPLAY");
    do
    {
    printf("\nEnter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:push();
            break;
        case 2:pop();
            break;
        case 3:peek();
            break;
        case 4:isempty();
            break;
        case 5:isfull();
            break;
        case 6:display();
            break;

    }
    printf("\n Do you want to continue ?");
    scanf("%s",&c);
    }while(c=='y'||c=='Y');

}
