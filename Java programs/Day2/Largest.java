import java.util.Scanner;
class Largest{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int max=0,i,j;
    int a[][] = new int[10][10];
    System.out.println("Enter rows and columns of the matrix ");
    int p = sc.nextInt();
    int q = sc.nextInt();
    System.out.println("Enter the elements of the matrix ");
    for(i=0; i<p; i++){
      for(j=0; j<q; j++){
        a[i][j] = sc.nextInt();
        if(a[i][j]>max)
          max = a[i][j];
      }
    }
    System.out.println("Largest element in the matrix is : "+max);
    System.out.println("The transpose of the matrix is : ");
    for(i=0; i<q; i++){
      for(j=0; j<p; j++)
        System.out.print(a[j][i]+ " ");
      System.out.println();
    }
  }
}
