#include<stdio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node *llink;
    struct node *rlink;
};
struct node *insert_begining(struct node *head)
{
    int data;
    printf("Enter element : ");
    scanf("%d",&data);
    if(head == NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->item = data;
        head->llink = NULL;
        head->rlink = NULL;
        return head;
    }
    else{
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->item = data;
        temp->llink = NULL;
        temp->rlink = head;
        head->llink = temp;
        return (temp);
    }

}
struct node *insert_end(struct node *head)
{
    int data;
    struct node *temp, *current=head;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d",&data);
    temp->item = data;
    temp->rlink = NULL;
    if(head == NULL)
    {
        temp->llink = NULL;
        return (temp);
    }
    while(current->rlink != NULL)
        current = current->rlink;
    temp->llink = current;
    current->rlink = temp;
    display(head);
    return (head);
}
void insert_after(struct node *head, int search)
{
    struct node *temp, *current=head;
    int data;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d",&data);
    temp->item = data;
    while(current != NULL)
    {
        if(current->item == search)
        {
            temp->llink = current;
            temp->rlink = current->rlink;
            if(current->rlink != NULL)
                (current->rlink)->llink = temp;
            current->rlink = temp;
        }
        current = current->rlink;
    }
}
struct node *delete_beginning(struct node *head)
{
    if(head == NULL)
        printf("\nEmpty");
    else if(head->rlink == NULL)
    {
        free(head);
        return NULL;
    }
    else{
        struct node *current=head;
        head = head->rlink;
        head->llink = NULL;
        free(current);
    }
    return (head);
}
void delete_end(struct node *head)
{
    if(head == NULL)
        printf("\nEmpty");
    else if(head->rlink == NULL)
    {
        free(head);
        return NULL;
    }
    else{
        struct node *current=head;
        while(current->rlink != NULL)
            current = current->rlink;
        (current->llink)->rlink = NULL;
        free(current);
    }
}
struct node *delete_node(struct node *head, int search)
{
    struct node *current=head,*temp;
    if(head->item == search)
    {
        temp = head;
        head = head->rlink;
        head->llink = NULL;
        free(temp);
        return (head);
    }
    else{
        current = current->rlink;
        while(current != NULL)
        {
            if(current->item == search)
            {
                temp = current;
                (current->llink)->rlink = current->rlink;
                if(current->rlink != NULL)
                    (current->rlink)->llink = current->llink;
                free(temp);
                return (head);
            }
            current = current->rlink;
        }
    }
}
void display(struct node *head)
{
    struct node *current=head;
    while(current != NULL)
    {
        printf("%d\t",current->item);
        current = current->rlink;
    }
}
void main()
{
    int a,c,h;
    char ch;
    struct node *head = NULL;

    printf("\n\t\tMENU");
    printf("\n 1)Insert at the beginning \n 2)Insert at the end \n 3)Insert after a specified node \n 4)Delete from the beginning \n 5)Delete from the end \n 6)Delete a specified node \n 7)Display");
    do{
        printf("\n Enter you choice : ");
        scanf("%d",&c);
        if(c == 1)
        {
            head = insert_begining(head);
            display(head);
        }
        else if(c == 2)
        {
            head = insert_end(head);
        }
        else if(c == 3)
        {
            printf("Enter node after which you want to enter element :");
            scanf("%d",&h);
            insert_after(head,h);
            display(head);
        }
        else if(c == 4)
        {
            head = delete_beginning(head);
            display(head);
        }
        else if(c == 5)
        {
            delete_end(head);
            display(head);
        }
        else if(c == 6)
        {
            printf("Enter node which you want to delete :");
            scanf("%d",&h);
            delete_node(head,h);
            display(head);
        }
        else if(c == 7)
            display(head);
        else
            printf("Enter valid choice");
        printf("\nDo you want to continue ? (y/n)");
        scanf("%s",&ch);
    }while(ch == 'y' || ch == 'Y');
}
