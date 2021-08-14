import java.util.*;
class Tokenizer{
  public static void main(String args[]){
    int n,sum=0;
    try{
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter numbers with one space gap:");
      String s = sc.nextLine();
      StringTokenizer st = new StringTokenizer(s, " ");
      System.out.println("The numbers are :");
      while (st.hasMoreTokens()){
        String temp = st.nextToken();
        n = Integer.parseInt(temp);
        System.out.println(n);
        sum = sum + n;
      }
      System.out.println("Sum : " + sum);
    }catch(NumberFormatException e){
      System.out.println("Exception: "+e);
    }
    catch(Exception e){
      System.out.println("Exception: "+e);
    }
  }
}
