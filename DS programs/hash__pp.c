#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int linear[MAX];
int quadratic[MAX];
int size;
struct node
{
     int key;
     struct node *next;
}*chaining_array[MAX] = {NULL};
void initialize()
{
     int i;
     for(i=0;i<size;i++)
     {
          linear[i] = -1;
          quadratic[i] = -1;
     }
}
void display(int a[])
{
     int i;
     printf("Hash table: ");
     for(i = 0; i < size; i++)
     {
        if(a[i] != -1)
         printf("%d ", a[i]);
         else
         printf("- ");
     }
}
void display_chaining()
{
     int i;
     struct node *ptr;
     printf("Hash table:\n");
     for(i = 0; i < size; i++)
     {
         printf("%d - ", i);
         ptr = chaining_array[i];
          while(ptr != NULL)
          {
               printf("%d -> ", ptr -> key);
               ptr = ptr -> next;
          }
          printf("NULL\n");
     }
}
void linear_probing(int key)
{
     int i,j,hash,h,flag = 1;
     for(i = 0; i < size; i++)
     {
          if(linear[i] == -1)
               flag = 0;
     }
     if(flag == 1)
     {
          printf("\nHash table is full.");
          return;
     }
     hash = h = key % size;
     if(linear[h] != -1)
     {
          for(j = 1; j < size; j++)
          {
               hash=(h+j)%size;
               if(linear[hash] == -1)
                    break;
          }
     }
     linear[hash] = key;
     if(key != -1)
          display(linear);
}
void quadratic_probing(int key)
{
     int i, hash,h,flag = 1,j;
     for(i = 0; i < size; i++)
     {
          if(quadratic[i] == -1)
               flag = 0;
     }
     if(flag == 1)
     {
          printf("\nHash table is full.");
          return;
     }
     hash = h = key % size;
     if(quadratic[h] != -1)
     {
          for(j = 1; j < size; j++)
          {
               hash =(h+(j*j))%size;
               if(quadratic[hash] == -1)
                    break;
          }
     }
     quadratic[hash] = key;
     if(key != -1)
          display(quadratic);
}
void chain_linking(int key)
{
     int i, hash;
     struct node *newnode, *ptr;
     hash = key % size;
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode -> key = key;
     newnode -> next = NULL;
     if(chaining_array[hash] == NULL)
          chaining_array[hash] = newnode;
     else
     {
          ptr = chaining_array[hash];
          while(ptr -> next != NULL)
               ptr = ptr -> next;
          ptr -> next = newnode;
     }
     if(key != -1)
          display_chaining();
}
void main()
{
     int ch, key;
     printf("Enter hash table size: ");
     scanf("%d", &size);
     initialize();
     printf("\n\t\tMENU \n");
     printf(" 1. Linear Probing\n 2. Quadratic Probing\n 3. Chaining: ");
     printf("\n Enter option : ");
     scanf("%d", &ch);
     do
     {
          printf("\n Enter key to insert (-1 to exit): ");
          scanf("%d", &key);
          switch(ch)
          {
               case 1: linear_probing(key);
               break;
               case 2: quadratic_probing(key);
               break;
               case 3: chain_linking(key);
               break;
               default:printf("Enter valid option ");
          }
     }while(key != -1);
}

