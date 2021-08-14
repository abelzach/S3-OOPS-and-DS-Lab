import java.util.Scanner;
public class QuickSort{
    public static void quicksort(String a[], int m, int n){
        int i,j;
        String k,temp;
        if(m<n)
        {
            i=m; j=n;
            k = a[m];
            do{
                do{
                    i++;
                }while((a[i].compareTo(k)<=1)&&(i<n-1));
                do{
                    j--;
                }while((a[j].compareTo(k)>=1)&&(j>m));
                if(i<j)
                {
                    temp = a[i];
                    a[i]= a[j];
                    a[j] = temp;
                }
            }while(i < j);
            temp = a[j];
            a[j]= a[m];
            a[m] = temp;
            quicksort(a,m,j-1);
            quicksort(a,j+1,n);
        }
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int i;
        System.out.println("Enter the number of names : ");
        int n = sc.nextInt();
        String[] a = new String[n];
        System.out.println("Enter the names :");
        for(i=0; i<a.length; i++)
            a[i] = sc.nextLine();
        quicksort(a,0,n);
        System.out.println("Sorted names : ");
        for(i=0; i<a.length; i++)
            System.out.println(a[i]+" ");
    }
}
