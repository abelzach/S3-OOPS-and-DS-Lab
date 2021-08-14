#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *llink,*rlink;
}*a[20]={NULL},*front=NULL,*rear=NULL;
int count = 1;
void insert(int item){
    struct node *new = malloc(sizeof(struct node));
    new->data = item;
    new->llink = NULL;
    new->rlink = NULL;
    if(front == NULL)
        front = new;
    else{
        rear->rlink = new;
        new->llink = rear;
    }
    rear = new;
}
void delete(){
    struct node *temp;
    temp=front;
    if(temp == NULL)
        printf("Overflow");
    else if(temp->rlink!=NULL)
    {
        front = front->rlink;
        front->llink = NULL;
        temp->rlink = NULL;
        a[count++] = temp;
    }
    else{
        a[count++] = temp;
    }
}
void swap(struct node **a, struct node **b)
{
    struct node *t = *a;
    *a = *b;
    *b = t;
}
void Heapify(struct node *a[],int n,int i){
    int min = i;
    int lc = i*2;
    int rc = i*2+1;
    if(lc<n && a[lc]->data < a[min]->data)
        min = lc;
    if(rc<n && a[rc]->data < a[min]->data)
        min = rc;
    if(min != i){
        swap(&a[min],&a[i]);
        Heapify(a,n,min);
    }
}
void Heapsort(struct node *a[],int n){
    int i;
    for(i=(n/2)-1;i>0;i--)
        Heapify(a,n,i);
    for(i=n-1;i>0;i--){
        swap(&a[1],&a[i]);
        Heapify(a,i,1);
    }
}
void main(){
    printf("Enter number of nodes : ");
    int n,v,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Insert value : ");
        scanf("%d",&v);
        insert(v);
    }
    for(i=0;i<n;i++){
        delete();
    }
    for(i=1;i<count;i++)
        printf("%d\t",a[i]->data);
    Heapsort(a,count);
    printf("\nAfter sorting : ");
    for(i=1;i<count;i++)
        printf("%d\t",a[i]->data);
}