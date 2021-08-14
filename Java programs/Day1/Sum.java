import java.util.Scanner;
class Sum{
  public static void main(String args[]){
    int sum=0,r;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number : ");
    int n = sc.nextInt();
    while(n!=0){
      r=n%10;
      sum=sum+r;
      n=n/10;
    }
    System.out.println("Sum of digits : "+sum);
  }
}