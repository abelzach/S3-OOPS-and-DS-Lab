#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *lchild;
    struct tree *rchild;
}*root,*pos = NULL,*par = NULL;
void inorder(struct tree *root)
{
    if(root != NULL)
    {
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
}
void search(struct tree *root, int item)
{
    if(root != NULL)
    {
        if(root->data == item)
        {
            pos = root;
            return;
        }
        else{
            search(root->lchild,item);
            search(root->rchild,item);
        }
    }
    return;
}
struct tree *Build_tree()
{
    int x;
	char ch;
	struct tree *current;
	current = (struct tree*)malloc(sizeof(struct tree));
	current->lchild = NULL;
	current->rchild = NULL;
	printf("\n Enter the node : ");
	scanf(" %d",&x);
	current->data = x;
	printf(" Does %d have a left child? ",current->data);
	scanf(" %c",&ch);
	if(ch == 'y' || ch == 'Y')
		current->lchild = Build_tree();
	printf(" Does %d have a right child?",current->data);
	scanf(" %c",&ch);
	if(ch=='y' ||ch == 'Y')
		current->rchild = Build_tree();
	return current;
}
struct tree *create_node(int item)
{
    struct tree *temp;
    temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = item;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
void insert(struct tree *root,int item)
{
    int it;
    char ch;
    search(root,item);
    if(pos == NULL)
        printf("Search element not present");
    else{
        printf(" Left child or Right child (l/r) ?");
        scanf(" %s",&ch);
        printf(" Enter node to insert : ");
        scanf(" %d",&it);
        if(ch == 'l' || ch == 'L')
        {
            if(pos->lchild == NULL)
                pos->lchild = create_node(it);
            else
                printf(" Insertion not Possible ");
        }
        else if(ch == 'r' || ch == 'R')
        {
             if(pos->rchild == NULL)
                pos->rchild = create_node(it);
            else
                printf(" Insertion not Possible ");
        }
    }
}
void Find_parent(struct tree *root,int search)
{
    if(root != NULL)
    {
        if(root->lchild != NULL)
        {
            if((root->lchild)->data == search)
            {
                par = root;
                return;
            }
        }
        if(root->rchild != NULL)
        {
            if(root->rchild->data == search)
            {
                par = root;
                return;
            }
        }
        Find_parent(root->lchild,search);
        Find_parent(root->rchild,search);
    }
    return;
}
void delete_node(struct tree *root,int item)
{
    struct tree *current = root;
    search(current,item);
    if(pos == NULL)
        printf(" Element not Found ");
    if(pos == root && pos->lchild == NULL && pos->rchild == NULL)
        root = NULL;
    else{
        if(pos->lchild == NULL && pos->rchild == NULL)
        {
            Find_parent(current,pos->data);
            if (par->lchild == pos)
                par->lchild = NULL;
            else
                par->rchild = NULL;
        }
        else
            printf(" Deletion is not possible as it is not a leaf node");
    }
}
void main()
{
    int item,c;
    char cho;
    printf(" Build your binary tree : ");
    root = Build_tree();
    inorder(root);
    printf("\n\t\tMENU \n 1)Insert node \n 2)Delete node \n 3)Search for a node ");
    do{
        printf("\n Enter your choice : ");
        scanf(" %d",&c);
        if(c == 1)
        {
            printf(" Enter which node do u want a child node ");
            scanf(" %d",&item);
            insert(root,item);
            inorder(root);
        }
        else if(c == 2){
            printf(" Enter node to delete : ");
            scanf(" %d",&item);
            delete_node(root,item);
            inorder(root);
        }
        else if(c == 3){
            pos = NULL;
            printf(" Enter node to search : ");
            scanf(" %d",&item);
            search(root,item);
            if(pos == NULL)
                printf(" Search element %d not present ",item);
            else
                printf(" %d is present ",pos->data);
        }
        else
            printf(" Enter valid choice");
        printf("\n Do you want to continue (y/n) ");
        scanf(" %s",&cho);
    }while(cho == 'y' || cho == 'Y');
}
