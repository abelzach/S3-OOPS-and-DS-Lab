import java.util.Scanner;
class Multiply{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int k,i,j;
    int a[][] = new int[10][10];
    int b[][] = new int[10][10];
    System.out.println("Enter rows and columns of first matrix ");
    int p = sc.nextInt();
    int q = sc.nextInt();
    System.out.println("Enter the elements of the first matrix ");
    for(i=0; i<p; i++){
      for(j=0; j<q; j++){
        a[i][j] = sc.nextInt();
      }
    }
    System.out.println("Enter rows and columns of second matrix ");
    int m = sc.nextInt();
    int n = sc.nextInt();
    System.out.println("Enter the elements of the second matrix ");
    for(i=0; i<m; i++){
      for(j=0; j<n; j++){
        b[i][j] = sc.nextInt();
      }
    }
    int c[][] = new int[p][n];
    if(q==m)
    {
      System.out.println("The product of first and second matrix is:");
      for(i=0; i<p; i++){
        for(j=0; j<n; j++){
          for(k=0;k<m; k++)
            c[i][j]+=a[i][k]*b[k][j];
          System.out.print(c[i][j]+" ");
        }
        System.out.println();
      }
    }
    else{
      System.out.println("The matrices cannot be multiplied");
    }
    
  }
}