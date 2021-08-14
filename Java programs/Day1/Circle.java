import java.util.Scanner;
class Circle{
  public static void main(String args[]){
    double area;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the radius of the circle");
    double r = sc.nextDouble();
    System.out.println("Radius of circle is "+r);
    area=3.14*r*r;
    System.out.println("Area of circle is "+area);
  }
}