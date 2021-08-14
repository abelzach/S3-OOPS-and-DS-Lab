import java.util.Scanner;
class Binary{
  public static int BinarySearch(int a[], int low, int high, int x)
  {
    int mid;
    while(low<=high)
    {
      mid = (low+high)/2;
      if(x < a[mid])
        high = mid - 1;
      else if(x > a[mid])
        low = mid + 1;
      else 
        return mid;
    }
    return (-1);
  }
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int r,i,temp,j;
    int a[] = new int[10];
    System.out.println("How many numbers do you want to enter : ");
    int n = sc.nextInt();
    System.out.println("Enter the numbers : ");
    for(i=0; i<n; i++)
      a[i] = sc.nextInt();
    for(i = 0; i<n; i++)
    {
      for(j=0; j<n-1-i; j++)
      {
        if(a[j]>a[j+1])
        {
          temp = a[j];
          a[j] = a[j+1];
          a[j+1] = temp;
        }
      }
    }
    for(i=0; i<n; i++)
      System.out.print(a[i]+"\t");
    System.out.println("\nEnter the number you want to search using binary search : ");
    int x = sc.nextInt();
    r = BinarySearch(a,0,n-1,x);
    if(r == -1)
      System.out.println("The number does not exist ");
    else
      System.out.println("The number "+x+" is present at position "+r);
  }
}