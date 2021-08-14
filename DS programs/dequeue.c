#include<stdio.h>
#define max 5
int front=-1,rear=-1;
int queue[max];
void insert_rear()
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
         next = (((rear)%(max))+1);
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
void insert_front()
{
    int item;
    if(((rear%(max))+1) == front)
        printf("Queue is full");
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if(front == 0)
            front = max-1;
        else
            front = front-1;
        printf("Enter element : ");
        scanf("%d",&item);
        queue[front] = item;
    }

}
void delete_rear()
{
    int item;
    if (front == -1)
        printf("Queue is Empty");
    else
    {
        item = queue[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if(rear == 0)
            rear = max-1;
        else
            rear = rear-1;
        printf("Deleted element is %d",item);
    }
}
void delete_front()
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
void display(){
    int i;
	printf("\nQueue status is: ");
    if (front==-1)
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
	int c;
	char ch;
    printf("\n\t\t\tMENU\n 1)INSERT AT FRONT\n 2)INSERT AT REAR\n 3)DELETE FROM FRONT\n 4)DELETE FROM REAR\n 5)DISPLAY");
    do{
        printf("\nEnter your choice : ");
		scanf("%d",&c);
		switch(c){
			case 1:insert_front();
                    break;
			case 2:insert_rear();
                    break;
			case 3:delete_front();
                    break;
			case 4:delete_rear();
                    break;
			case 5:display();
                    break;
		}
		printf("\nDo you want to continue(y/n) ");
		scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
}
