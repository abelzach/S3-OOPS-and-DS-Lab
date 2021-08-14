import java.util.Scanner;
class Palindrome{
  public static void main(String args[]){
    int l,i;
    String a,b="";
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the string you want to check for palindrome : ");
    a = sc.nextLine();
    l = a.length();
    for(i=l-1; i>=0; i--)
      b += a.charAt(i);
    if(a.equalsIgnoreCase(b))
      System.out.println(a+" is a palindrome");
    else
      System.out.println(a+" is not a palindrome");
  }
}