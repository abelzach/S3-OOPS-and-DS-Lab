#include<stdio.h>
void bubble(int a[],int n)
{
    int i,j,temp;
    for(i = 0; i<n; i++)
        for(j=0; j<n-1-i; j++)
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    printf(" Sorted list : ");
    for(i=0; i<n; i++)
        printf("%d \t",a[i]);
}
void insertion(int a[],int n)
{
    int i,k,y;
    for(k=1; k<n; k++)
    {
        y = a[k];
        for(i=k-1; i>=0 && y<a[i]; i--)
            a[i+1] = a[i];
        a[i+1] = y;
    }
    printf(" Sorted list : ");
    for(i=0; i<n; i++)
        printf("%d \t",a[i]);
}
void selection(int a[], int n)
{
    int i,j,temp;
    for(i = 0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    printf(" Sorted list : ");
    for(i=0; i<n; i++)
        printf("%d \t",a[i]);
}
void main()
{
    int i,n,a[25],c;
    printf(" Enter the number of elements : ");
    scanf("%d",&n);
    printf(" Enter the elements : \n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("\n\t\t MENU \n 1)Bubble sort \n 2)Insertion sort \n 3)Selection sort \n");
    printf(" Enter your choice for sorting :");
    scanf("%d",&c);
    if(c == 1)
        bubble(a,n);
    else if(c == 2)
        insertion(a,n);
    else if(c == 3)
        selection(a,n);
    else
        printf(" Enter valid choice ");
}
