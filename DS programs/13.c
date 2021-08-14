#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *lchild;
    struct tree *rchild;
};
struct tree *newNode(int item)
{
    struct tree *temp;
    temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = item;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
void inorder(struct tree *root)
{
    if(root != NULL)
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);
    }
}
struct tree *search(struct tree *root,int item)
{
    if(root == NULL || root->data == item)
        return root;
    else if(root->data > item)
        return search(root->lchild,item);
    else 
        return search(root->rchild,item);
}
struct tree *insert(struct tree *root,int item)
{
    if(root == NULL)
        return newNode(item);
    else if(root->data > item)
        root->lchild = insert(root->lchild,item);
    else
        root->rchild = insert(root->rchild,item);
    return root;
}
struct tree *minValue(struct tree *root)
{
    struct tree *current;
    current = root;
    while(current && current->lchild != NULL)
        current = current->lchild;
    return current;
}
struct tree *deleteItem(struct tree *root,int item)
{
    if(root == NULL)
        return root;
    if(root->data > item)
        root->lchild = deleteItem(root->lchild,item);
    else if(root->data < item)
        root->rchild = deleteItem(root->rchild,item);
    else{
        if(root->lchild == NULL)
        {
            struct tree *temp = root->rchild;
            free(root);
            return temp;
        }
        if(root->rchild == NULL)
        {
            struct tree *temp = root->lchild;
            free(root);
            return temp;
        }
        struct tree *temp = minValue(root->rchild);
        root->data = temp->data;
        root->rchild = deleteItem(root->rchild,temp->data);
    }
}

void main()
{
    struct tree *root=NULL,*pos;
    int choice,item;
    char ch;
    printf("\n\t\tMENU \n 1)Insert \n 2)Delete \n 3)Search \n 4)Inorder \n 5) Mirror of a given node ");
    do{
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter item to insert :");
            scanf("%d",&item);
            root = insert(root,item);
            inorder(root);
        }
        else if(choice == 2)
        {
            printf("Enter item to delete :");
            scanf("%d",&item);
            root = deleteItem(root,item);
            inorder(root);
        }
        else if(choice == 3)
        {
            pos = NULL;
            printf("Enter item to search : ");
            scanf("%d",&item);
            pos = search(root,item);
            if(pos == NULL)
                printf("Search element not found");
            else
                printf("%d is present",pos->data);
        }
        else if(choice == 4)
            inorder(root);
        else if(choice == 5)
        {
            printf("Enter element to find its mirror image ");
            scanf("%d",&item);
            int m = mirror(item);
            printf("\n%d",m);
        }
        else
            printf("Enter valid choice ");
        printf("\nDo you want to continue? ");
        scanf("%s",&ch);
    }while(ch=='y' || ch=='Y');
}
