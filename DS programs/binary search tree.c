#include<stdio.h>
#include<stdlib.h>
int max=0;
int k=-1;
int a[20];
struct tree
{
    int data;
    struct tree *lchild;
    struct tree *rchild;
};
void insertion_sort()
{
    int i,y,j;
    int n = 10;
    for(j=1;j<=k;j++){
        y=a[j];
        for(i=j-1;i>=0 && y<a[i]; i--){
            a[i+1] = a[i];
        }
        a[i+1] = y;
    }
}
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
        printf("%d\t",root->data);
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
    else if(item < root->data)
        root->lchild = insert(root->lchild,item);
    else if(item > root->data)
        root->rchild = insert(root->rchild,item);
    return root;
}
struct tree *minValue(struct tree *root)
{
    struct tree *current;
    current = root;
    while(current && (current->lchild!=NULL))
            current = current->lchild;
    return current;
}
struct tree *deleteItem(struct tree *root,int item)
{
    if(root == NULL)
        return root;
    if(item < root->data)
        root->lchild = deleteItem(root->lchild,item);
    else if(item > root->data)
        root->rchild = deleteItem(root->rchild,item);
    else{
        if(root->lchild == NULL)
        {
            struct tree *temp = root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild == NULL)
        {
            struct tree *temp = root->lchild;
            free(root);
            return temp;
        }
        struct tree *temp = minValue(root->rchild);
        root->data = temp->data;
        root->rchild = deleteItem(root->rchild,temp->data);
    }
    return root;
}
void Leaf(struct tree *root)
{
    if(root != NULL)
    {
        if(root->lchild == NULL && root->rchild == NULL)
        {
            printf("%d\t",root->data);
            if(max<root->data)
                max = root->data;
        }
        else{
            Leaf(root->lchild);
            Leaf(root->rchild);
        }
    }
}
void nonleaf(struct tree *root)
{
    if(root!=NULL)
    {
        if(!(root->lchild==NULL&&root->rchild==NULL))
        {
            k++;
            a[k]=root->data;
        }
        nonleaf(root->lchild);
        nonleaf(root->rchild);
    }   
}
void Level(struct tree *root,int height,int item){
    if(root!=NULL){
        if(root->data==item)    
            printf("%d",height);
        else{
            Level(root->lchild,height+1,item);
            Level(root->rchild,height+1,item);
        }
    }
}
int Height(struct tree *root){
    int lht,rht;
    if(root!=NULL){
        lht=Height(root->lchild);
        rht=Height(root->rchild);
        if(lht>rht)
            return 1+lht;
        else
            return 1+rht;
    }
    else
        return -1;
}
void main()
{
    int c,l;
    char ch;
    struct tree *root = NULL,*pos;
    printf("\n\t\tMENU\n 1)Insertion \n 2)Deletion \n 3)Inorder Traversal \n 4)Search \n 5)Leaf ");
    do{
        printf("\n Enter your choice : ");
        scanf("%d",&c);
        if(c == 1)
        {
            printf(" Enter element to insert : ");
            scanf("%d",&l);
            root = insert(root,l);
            inorder(root);
        }
        else if(c == 2)
        {
            printf(" Enter element to delete : ");
            scanf("%d",&l);
            root = deleteItem(root,l);
            inorder(root);
        }
        else if(c == 3)
            inorder(root);
        else if(c == 4)
        {
            pos = NULL;
            printf(" Enter element to search for : ");
            scanf("%d",&l);
            pos = search(root,l);
            if(pos == NULL)
                printf("%d not found \n",l);
            else
                printf(" %d is present \n",pos->data);
        }
        else if(c==5)
        {
            Leaf(root);
            printf("\nMaximum leaf node is %d\n",max);
            deleteItem(root,max);
            inorder(root);
        }
        else if(c==6){
            printf("Non leaf nodes in ascending order : ");
            nonleaf(root);
            insertion_sort();
            for(int i=0;i<=k;i++)
                printf("%d\t",a[i]);
        }
        else if(c == 7)
        {
            printf(" Enter element to find height : ");
            scanf("%d",&l);
            Level(root,0,l);
        }
        else if(c == 8)
        {
            printf(" Height of the tree : ");
            int h = Height(root);
            printf("%d",h);
        }
        printf("\n Do you want to continue ?");
        scanf("%s",&ch);
    }while(ch == 'y' || ch == 'Y');
}
