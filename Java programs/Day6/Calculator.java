import java.util.Scanner;
class Calculator{
  public static void main(String args[]){
    int res;
    Scanner sc = new Scanner(System.in);
    System.out.println("\t\t\tCalculator");
    System.out.println(" 1)Addition \n 2)Subtraction \n 3)Multiplication \n 4)Divison");
    System.out.println("Enter two numbers : ");
    try{
      int i = sc.nextInt();
      int j = sc.nextInt();
      System.out.println("Enter choice for operator : ");
      int ch = sc.nextInt();
      switch(ch){
        case 1: res = i + j;
                System.out.println(i+" + "+j+" = "+res);
                break;
        case 2: res = i - j;
                System.out.println(i+" - "+j+" = "+res);
                break;
        case 3: res = i * j;
                System.out.println(i+" * "+j+" = "+res);
                break;
        case 4:
                res = i / j;
                System.out.println(i+" / "+j+" = "+res);
      }
    }catch(ArithmeticException e){
      System.out.println("Exception : "+e);
    }
    catch(NumberFormatException e){
      System.out.println("Exception : "+e);
    }
    catch(Exception e){
      System.out.println("Exception : "+e);
    }
  }
}