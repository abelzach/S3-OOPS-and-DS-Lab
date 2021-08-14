#include<stdio.h>
void adjust(int a[],int i,int n)
{
    int r,l,largest=i,temp;
    r = i*2 + 1;
    l = i*2;
    if(l<=n && a[l]>a[largest])
        largest = l;
    if(r<=n && a[r]>a[largest])
        largest = r;
    if(largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        adjust(a,largest,n);
    }
}
void Heap_sort(int a[],int n)
{
    int i,temp;
    for(i = n/2; i > 0; --i)
        adjust(a,i,n);
    for(i = n; i > 0; --i)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        adjust(a,1,i-1);
    }
}

void main()
{
    int a[20],n,i;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter elements ");
    for(i=1;i <= n; i++)
        scanf("%d",&a[i]);
    printf("Performing Heap sort \n");
    Heap_sort(a,n);
    for(i=1;i <= n; i++)
        printf("%d\t",a[i]);
}
