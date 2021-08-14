#include<stdio.h>
int a[20];
int pos;
void Build_tree(int index)
{
    if(index != 0)
    {
        char ch;
        int item;
        printf("\n Enter node : ");
        scanf(" %d",&item);
        a[index] = item;
        printf(" Does %d have a left child : ",a[index]);
        scanf(" %s",&ch);
        if(ch == 'y' || ch == 'Y')
            Build_tree(2*index);
        else
            Build_tree(0);
        printf(" Does %d have a right child : ",a[index]);
        scanf(" %s",&ch);
        if(ch == 'y' || ch == 'Y')
            Build_tree(2*index+1);
        else
            Build_tree(0);
    }
}
void inorder(int index)
{
    if(index > 0 && a[index]!=0)
    {
        inorder(index*2);
        printf("%d\t",a[index]);
        inorder(index*2+1);
    }
}
void preorder(int index)
{
    if(index > 0 && a[index]!=0)
    {
        printf("%d\t",a[index]);
        preorder(index*2);
        preorder(index*2+1);
    }
}
void postorder(int index)
{
    if(index > 0 && a[index]!=0)
    {
        postorder(index*2);
        postorder(index*2+1);
        printf("%d\t",a[index]);
    }
}
void search(int index,int item)
{
    if(index > 0 && a[index]!=0)
    {
        if(a[index] == item)
        {
            pos = index;
            return;
        }
        else{
            search(index*2,item);
            search(index*2+1,item);
        }
    }
    return;
}
void insert(int node)
{
    char c;
    int item;
    search(1,node);
    if(pos == 0)
        printf(" Search element %d not present ",node);
    else{
        printf("Right node or left node ? ");
        scanf("%s",&c);
        printf(" Enter node to insert ");
        scanf(" %d",&item);
        if(c == 'l' || c == 'L')
        {
            if(a[pos*2] == 0)
                a[pos*2] = item;
            else
                printf("Insertion is not possible\n");
        }
        if(c == 'r' || c == 'R')
        {
            if(a[pos*2+1] == 0)
                a[pos*2+1] = item;
            else
                printf("Insertion is not possible\n");
        }
    }
}
void delete_node(int item)
{
    search(1,item);
    if(pos == 0)
        printf(" Search element %d not present ",item);
    else if(a[pos*2] == 0 && a[pos*2+1] == 0)
        a[pos] = 0;
    else
        printf("\nDeletion is not possible as the node is not a leaf node\n");
}
void display()
{
    printf("Inorder   : ");
    inorder(1);
    printf("\nPreorder  : ");
    preorder(1);
    printf("\nPostorder : ");
    postorder(1);
}
void main()
{
    int c,node,item;
    char cho;
    printf(" Build your binary tree : ");
    Build_tree(1);
    display();
    printf("\n\t\tMENU \n 1)Insert node \n 2)Delete node \n 3)Search for a node ");
    do{
        printf("\n Enter your choice : ");
        scanf(" %d",&c);
        if(c == 1)
        {
            printf(" Enter which node do u want a child node ");
            scanf(" %d",&node);
            insert(node);
            display();
        }
        else if(c == 2){
            printf(" Enter node to delete : ");
            scanf(" %d",&item);
            delete_node(item);
            display();
        }
        else if(c == 3){
            printf(" Enter node to search : ");
            scanf(" %d",&item);
            search(1,item);
            if(pos == 0)
                printf(" Search element %d not present ",item);
            else
                printf(" %d is present at %d \n",item,pos);
        }
        else
            printf(" Enter valid choice");
        printf("\n Do you want to continue (y/n) ");
        scanf(" %s",&cho);
    }while(cho == 'y' || cho == 'Y');
}
