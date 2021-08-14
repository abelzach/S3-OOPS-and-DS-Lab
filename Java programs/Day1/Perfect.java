import java.util.Scanner;
class Perfect{
  public static void main(String args[]){
    int sum=0,r,i;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number: ");
    int n = sc.nextInt();
    for(i=1;i<=n/2;i++){
      r=n%i;
      if(r==0)
        sum=sum+i;
    }
    if(sum==n)
      System.out.println(n+" is a perfect number");
    else
      System.out.println(n+" is not a perfect number");
    sc.close();
  }
}