import java.util.Scanner;
class Freqchar{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int l,i,n=0;
    System.out.println("Enter the string : ");
    String a = sc.nextLine();
    System.out.println("Enter the character whose frequency you want to find out: ");
    char b = sc.next().charAt(0);
    l = a.length();
    for(i=0; i<l; i++)
    {
      char c = a.charAt(i);
      if(b == c)
        n++;
    }
    System.out.println("Frequency of '"+b+"' in the above string is : "+n);
  }
}