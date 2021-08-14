#include<stdio.h>
# define max 5
int rear=-1;
int front=-1;
int queue[max],cho;
void isfull()
{
    if(cho == 1){
        if(rear == max-1)
            printf("\nQueue is full");
        else
            printf("Queue is not full");
    }
    else if(cho == 2)
    {
        if((rear+1)%(max) == front)
            printf("\nQueue is full");
        else
            printf("Queue is not full");
    }

}
void isempty()
{
    if(front == -1)
    {
        printf("\nQueue is empty");
    }
    else
        printf("Queue is not empty");
}

void circular_insert()
{
    int item,next;
    if(front == -1)
    {
        front = 0;
        rear = 0;
        printf("Enter element : ");
        scanf("%d",&item);
        queue[rear]=item;
    }
    else
    {
         next = ((rear+1)%(max));
         if (next != front)
         {
            rear = next;
            printf("Enter element : ");
            scanf("%d",&item);
            queue[rear] = item;
         }
         else
         printf("Queue is full");
    }
}
void circular_delete()
{
    int item;
    if(front == -1)
        printf("Queue is empty");
    else
    {
        item = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front%(max))+1;
        printf("Deleted element is %d",item);
    }
}
void insert(){
    int item;
    if(rear == max-1)
    {
        printf("Queue is full");
    }
    else
    {
        if((front == -1)||(rear == -1))
            front =0;
        printf("Enter element : ");
        scanf("%d",&item);
        rear=rear+1;
        queue[rear]=item;
    }
}
void deleteq(){
    int item;
    if(front == -1||front>rear)
    {
        printf("\nQueue is empty");
    }
    else if(front == rear)
    {
        item = queue[front];
        front = -1;
        rear = -1;
        printf("Deleted element is : %d\n",item);
    }
    else
    {
        item = queue[front];
        front=front+1;
        printf("Deleted element is : %d\n",item);
    }
}
void display(){
	int i;
	printf("\nQueue status is: ");
    if (front == -1)
        printf("Queue empty.");
    else
    {
        for(i=front;i!=rear;i=(i+1)%(max))
            printf("%d ",queue[i]);
        printf("%d ",queue[i]);
    }
}
void main()
{
    int ch;
    char y;
    printf("\n\t\t\tMENU");

    printf("\n 1)QUEUE \n 2)CIRCULAR QUEUE ");
    printf("\n Enter your choice :");
    scanf("%d",&cho);
    const int c = cho;
    printf("\n 1)ISFULL \n 2)ISEMPTY\n 3)INSERT ELEMENT \n 4)DELETE ELEMENT \n 5)DISPLAY");
    do{
        printf("\n Enter your choice :");
        scanf("%d",&ch);
        if(ch == 1)
            isfull();
        else if(ch == 2)
            isempty();
        else if(ch == 3)
        {
            if(c == 1)
                insert();
            else if(c == 2)
                circular_insert();
        }
        else if(ch == 4)
        {
            if(c == 1)
                deleteq();
            else if(c == 2)
                circular_delete();
        }
        else if(ch == 5)
            display();
        printf("\n Do you want to continue (y/n)? ");
        scanf("%s",&y);
      }while(y=='y'||y=='Y');
}

