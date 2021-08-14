#include<stdio.h>
#define max 5
struct prior{
    int item;
    int priority;
};
int front=-1,rear=-1;
int highest(struct prior a[])
{
    if(front == -1){
        return -1;
    }
    else{

        int i,m=front;
        for(i=front+1; i<=rear; i++)
        {
            if(a[m].priority<a[i].priority)
                m = i;
        }
        return m;
    }
}
void dequeue(struct prior a[])
{
    int i,index;
        index = highest(a);
    if(index == -1)
        printf("Queue is empty");
    else if(front == rear)
    {
        front = -1;
        rear = -1;
        printf("Only element deleted ");
    }
    else if(index == rear)
    {
        rear--;
        printf("Highest priority element deleted");
    }
    else{
        for(i=index; i<rear; i++)
        {
            a[i].item = a[i+1].item;
            a[i].priority = a[i+1].priority;
        }
        rear--;
        printf("Highest priority element deleted");
    }
}
void enqueue(struct prior a[],int it, int pr)
{
    if(front == -1)
    {
        front = 0;
        rear = 0;
        a[rear].item = it;
        a[rear].priority = pr;
    }
    else if(rear == max-1)
    {
        printf("Queue is full");
    }
    else{
        rear++;
        a[rear].item = it;
        a[rear].priority = pr;
    }
}
void display(struct prior a[])
{
    int i;
    if(front == -1)
        printf("No elements ");
    else{
        for(i=front; i<=rear; i++)
        {
            printf("\nItem : %d \t Priority: %d",a[i].item,a[i].priority);
        }
    }

}
void main()
{
    int i,ch,x,it,pr;
    char y;
    struct prior s[max];
    printf("\n\t\t\t MENU \n 1)Insert into queue \n 2)Delete from queue \n 3) Display queue ");
    do{
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        if(ch == 1)
        {   printf("Enter the item : ");
            scanf("%d",&it);
            printf("Enter the priority : ");
            scanf("%d",&pr);
            enqueue(s,it,pr);
        }
        else if(ch == 2)
            dequeue(s);
        else if(ch == 3)
            display(s);
        printf("\nDo you want to continue (y/n)? : ");
        scanf("%s",&y);
    }while(y=='y'||y=='Y');

}
