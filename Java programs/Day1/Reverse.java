import java.util.Scanner;
class Reverse{ 
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    System.out.println("How many numbers do u want to input : ");
    int n = sc.nextInt();
    for(int i=0; i<n; i++)
    {
      System.out.println("Enter number "+ (i+1));
      int m = sc.nextInt();
      int r,rev=0;
      while(m!=0)
      {
        r = m%10;
        rev = rev*10 + r;
        m = m/10;
      }
      System.out.println("Reverse : "+ rev);
    }
  }
}