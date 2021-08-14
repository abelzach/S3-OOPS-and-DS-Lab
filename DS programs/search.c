#include<stdio.h>
void linear_search(int a[],int x, int pos, int n)
{
    if(pos < n)
    {
        if(a[pos] == x)
            printf("%d found at position %d",x,pos);
        else
            linear_search(a,x,pos+1,n);
    }
    else
        printf("%d not found ",x);
}
int binary(int a[], int l, int r, int x)
{
    int mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(a[mid] > x)
            r=mid-1;
        else if(a[mid] < x)
            l=mid+1;
        else
            return mid;
    }
    return -1;
}
void main()
{
    int a[25],x,temp,n,i,c,j;
    char ch;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("\n\t\tMENU\n 1)Linear Search \n 2)Binary Search ");
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        if(c == 1){
            printf("Enter number to search for : ");
            scanf("%d",&x);
            linear_search(a,x,0,n);
        }
        else if(c == 2)
        {
            for(i = 0; i<n; i++)
              for(j=0; j<n-1-i; j++)
                if(a[j]>a[j+1])
                {
                  temp = a[j];
                  a[j] = a[j+1];
                  a[j+1] = temp;
                }
            printf("Sorted list : ");
            for(i=0; i<n; i++)
                printf("%d \t",a[i]);
            printf("\nEnter number to search for : ");
            scanf("%d",&x);
            int d = binary(a,0,n-1,x);
            if(d == -1)
                printf("%d not found",x);
            else
                printf("%d found at %d",x,d);
        }
        else
            printf("Enter valid choice ");
        printf("\nDo you want to continue ? (y/n)");
        scanf("%s",&ch);
    }while(ch == 'y' || ch == 'Y');
}
