#include<stdio.h>
#include<stdlib.h>
#define max 30
int a[20][20],n,visited[30],v[20],f=-1,r=-1,queue[max];
struct node{
    int node;
    struct node *next;
}*list[20];
void adjacency()
{
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Is there a link between %d and %d (1/0) : ",v[i],v[j]);
            scanf("%d",&a[i][j]);
        }
    }
}
void adjacencylist()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        list[i] = (struct node *)malloc(sizeof(struct node));
        list[i]->node = v[i];
        list[i]->next = NULL;
        for(j=0; j<n; j++)
        {
            if(a[i][j] == 1)
            {
                struct node *current=list[i],*temp = (struct node*)malloc(sizeof(struct node));
                temp->node = v[j];
                temp->next = NULL;
                while(current->next != NULL)
                {
                    current=current->next;
                }
                current->next = temp;
            }
        }
    }
}
void displaylist()
{
    int i;
    for(i=0;i<n;i++)
    {
        struct node *temp = list[i];
        printf("%d ->",list[i]->node);
        temp = temp->next;
        while(temp != NULL)
        {
            printf(" %d ->",temp->node);
            temp = temp->next;
        }
        printf(" NULL");
        printf("\n");
    }
}
void display(){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}
void initialise()
{
    int i;
    for(i=0; i<n; i++)
    {
        visited[i]=0;
        queue[i] = 0;
    }
}
void dfs(int index)
{
    int j;
    visited[index]=1;
    printf("%d\t",v[index]);
    for(j=0;j<n; j++)
    {
        if(a[index][j]==1)
        {
            if(!visited[j])
                dfs(j);
        }
    }
}
void AddQueue(int item)
{
    if(f==-1 && r==-1)
        f = 0;
    r=r+1;
    queue[r]=item;
}
int DeleteQueue()
{
    int item;
    item = queue[f];
    if(f == r){
        f = -1;
        r = -1;
    }
    else
        f = f+1;
    return item;
}
void bfs(int index){
    int w;
    visited[index] = 1;
    printf("%d\t",v[index]);
    AddQueue(index);
    while(f != -1){
        w = DeleteQueue();
        for(int u=0; u < n; u++){
            if(a[w][u] == 1 && !visited[u]){
                AddQueue(u);
                visited[u] = 1;
                printf("%d\t",v[u]);
            }
        }
    }
}
void indegree(int node)
{
    int i,index,flag = 0,c=0;
    for(index=0; index<n; index++)
    {
        if(v[index] == node)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Node is not present ");
        return;
    }
    for(i=0;i<n;i++)
    {
        if(a[i][index] == 1)
            c++;
    }
    printf("\n In Degree : %d",c);
}
void outdegree(int node)
{
    int i,index,flag = 0,c=0;
    for(index=0; index<n; index++)
    {
        if(v[index] == node)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Node is not present ");
        return;
    }
    for(i=0;i<n;i++)
    {
        if(a[index][i] == 1)
            c++;
    }
    printf("\n Out Degree : %d",c);
}
void main(){
    int i,index,choice,node;
    initialise();
    char ch;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter the vertices : ");
    for(i=0; i<n; i++)
        scanf("%d",&v[i]);
    adjacency();
    printf("\n Adjacency matrix : \n");
    display();
    printf("\t\tMENU \n 1) Adjacency matrix \n 2) Adjacency list \n 3) In degree \n 4) Out degree \n 5) DFS \n 6) BFS \n");
    do{
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\n Adjacency matrix : \n");
                    display();
                    break;
            case 2:adjacencylist();
                    displaylist();
                    break;
            case 3:printf("Enter the node : ");
                    scanf("%d",&node);
                    indegree(node);
                    break;
            case 4:printf("Enter the node : ");
                    scanf("%d",&node);
                    outdegree(node);
                    break;
            case 5:printf("Enter the starting vertex ? ");
                    scanf("%d",&index);
                    dfs(index);
                    initialise();
                    break;
            case 6:printf("Enter the starting vertex ? ");
                    scanf("%d",&index);
                    bfs(index);
                    initialise();
                    break;
            default: printf("Enter valid choice ");
        }
        printf("\nDo you want to continue ? ");
        scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
}
