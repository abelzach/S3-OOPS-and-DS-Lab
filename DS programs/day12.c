#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[],int m,int n)
{
    int temp,i,j,k;
    if(m < n)
    {
        i=m; j=n-1;
        k = a[m];
        do{
            while((a[i] <= k)&&(i<n))
                i++;
            while(a[j] >= k && j>m)
                j--;
            if(i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j]= temp;
            }
        }while(i <= j);
        temp = a[j];
        a[j] = a[m];
        a[m]= temp;
        quicksort(a,m,j);
        quicksort(a,j+1,n);
    }
}
void Merge(int a[], int low, int mid, int high)
{
    int i=low, j=mid+1,k=low,b[25];
    while(i <= mid && j<= high)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if(i > mid)
        while(j <= high)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    else
        while(i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    for(k=low; k <= high; k++)
        a[k] = b[k];
}
void Mergesort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (high+low)/2;
        Mergesort(a,low,mid);
        Mergesort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}
void main()
{
    int i,n,a[25],c;
    printf(" Enter the number of elements : ");
    scanf("%d",&n);
    printf(" Enter the elements : \n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("\n\t\t MENU \n 1)QUICK sort \n 2)MERGE sort \n");
    printf(" Enter your choice for sorting :");
    scanf("%d",&c);
    if(c == 1)
        quicksort(a,0,n);
    else if(c == 2)
        Mergesort(a,0,n);
    else
        printf("Enter valid choice");
    printf("Sorted array :");
    for(i=0; i<n; i++)
        printf("%d \t",a[i]);
}
