#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node*link;
};
struct node*head;
void main(){
    int ch, item, pos;
    struct node*newNode,*currentNode,*prevNode,*nextNode,*ptr;
    do{
        printf("\n MAIN MENU \n 1. Insertion at the beginning \n 2. Insertion at the last \n 3.Insertion at a specified postiton \n 4. Reverse a linked list \n 5. Display The linked list \n Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the item to be inserted ");
            scanf("%d",&item);
            newNode=(struct node*)malloc(sizeof(struct node));
            newNode->link=NULL;
            if(head==NULL){
                head=newNode;
            }
            else{
             newNode->link=head;
             head=newNode;
            }
            break;
            case 2: printf("Enter the item to be inserted");
            scanf("%d",&item);
            newNode=(struct node*)malloc(sizeof(struct node));
            newNode->link=NULL;
            if(head==NULL){
                head=newNode;
            }
            else{
                ptr=head;
                while(ptr->link!=NULL){
                    ptr=ptr->link;
                }
                ptr->link=newNode;
                newNode->link=NULL;
            }
            break;
            case 3: printf("Enter the item ");
            scanf("%d",&item);
            newNode=(struct node*)malloc(sizeof(struct node));
            newNode->data=item;
            newNode->link=NULL;
            printf("Enter the position");
            scanf("%d",&pos);
            ptr=head;
            for(int i=1;i<pos-1;i++){
                ptr=ptr->link;
            }
            newNode->link=ptr->link;
            ptr->link=newNode;
            break;
            case 4: 
            printf("Reversal of Linked list");
            prevNode=NULL;
            currentNode=head;
            nextNode=head;
            while(nextNode!=NULL){
                nextNode=nextNode->link;
                currentNode->link=prevNode;
                prevNode=currentNode;
                currentNode=nextNode;
            }
            head=prevNode;
            break;
           case 5: if(head==NULL){
               printf("NOT POSSIBLE");
           }
          else
          {
              printf("Displaying elements");
              ptr=head;
              while(ptr!=NULL){
                  printf("The element are %d",ptr->data);
                  ptr=ptr->link;
              }
          }
           break;
        }
    }while(ch>=1 && ch<=6);
}