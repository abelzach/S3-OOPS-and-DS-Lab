import java.util.Scanner;
class NegetiveSizeException extends Exception{
  public NegetiveSizeException(String m) {
    super(m);
  }
}
class Negetivesize {
  static void check(int n)throws NegetiveSizeException{  
    if(n<0)
      throw new NegetiveSizeException("Negetive number");
  }
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int a[] = new int [20];
    int i;
    System.out.println("Enter number of values : ");
    int n = sc.nextInt();
    System.out.println("Enter the values of the array : ");
    try{
      for(i=0; i<n; i++)
      {
        a[i] = sc.nextInt();
        check(a[i]);
      }
    }catch(NegetiveSizeException e){
      System.out.println("Exception : "+e);
    }
    finally{
      System.out.println("The numbers are : ");
      for(i=0; i<n; i++)
        System.out.print(a[i]+"\t");
      System.out.println();
    }
  }
}