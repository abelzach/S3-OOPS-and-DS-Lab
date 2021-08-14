import java.util.Scanner;
class Employee {
    int age;
    String name;
    Scanner sc = new Scanner(System.in);
    public void input(){
        System.out.println("Enter name and age ");
        name = sc.nextLine();
        age = sc.nextInt();
    }
    public void output(){
        System.out.println("Name : "+name+" Age : "+age);
    }
}
public class Empdetails extends Employee{
    public static void quicksort(Employee e[],int m,int n){
        if(m<n){
            Employee temp;
            int i=m,j=n-1;
            Employee k=e[m];
            do{
                while(i<n&& e[i].age<=k.age)
                    i++;
                while(j>0 && e[j].age>k.age)
                    j--;
                if(i<j){
                    temp = e[i];
                    e[i] = e[j];
                    e[j] = temp;
                }
            }while(i<=j);
            temp=e[m];
            e[m] = e[j];
            e[j] = temp;
            quicksort(e,m,j-1);
            quicksort(e,j+1,n);
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of employees :");
        int n = sc.nextInt();
        Employee[] e = new Employee[n];
        System.out.println("Enter the details");
        for(int i =0;i<n;i++){
            e[i] = new Employee();
            e[i].input();
        }
        quicksort(e,0,n);
        for(int i =0;i<n;i++)
            e[i].output();
    }
}
