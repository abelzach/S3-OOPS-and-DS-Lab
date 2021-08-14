import java.util.Scanner;
class Employee{
  Scanner sc = new Scanner(System.in);
  int age;
  float salary;
  long phone_number;
  String name,address="";
  void Print_Salary(){
    System.out.println("The salary is  "+salary);
  }
  void input(){
    System.out.println("Enter the name : ");
    name = sc.nextLine();
    System.out.println("Enter the address : ");
    address = sc.nextLine();
    System.out.println("Enter the age : ");
    age = sc.nextInt();
    System.out.println("Enter phone number : ");
    phone_number = sc.nextLong();
    System.out.println("Enter the salary : ");
    salary = sc.nextFloat();
  }
  void Display(){
    System.out.println("Name : "+name);
    System.out.println("Age : "+age);
    System.out.println("Phone number : "+phone_number);
    System.out.println("Address : "+address);
    Print_Salary();
  }
}
class Officer extends Employee{
  String specialization;
  Officer(String a){
    specialization = a;
  }
  void display(){
    System.out.println("Specialization : "+specialization);
  }
}
class Manager extends Employee{
  String department;
  Manager(String a){
    department = a;
  }
  void display(){
    System.out.println("Department : "+department);
  }
}
class Main{
  public static void main(String args[]){
    Officer ob = new Officer("Artificial Intelligence");
    Manager om = new Manager("Computer");
    System.out.println("Enter the details of Officer ");
    ob.input();
    System.out.println("Enter the details of Manager ");
    om.input();
    System.out.println("The Officer is : ");
    ob.Display();
    ob.display();
    System.out.println("The Manager is : ");
    om.Display();
    om.display();
  }
}