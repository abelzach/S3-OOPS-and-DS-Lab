/*To create a class Student and inherit to subclasses Day_Scholar and Hosteler.
 And input details like name, sem, phone no.,address,dob. Day scholar has a data member bus_no.
  And hosteler had data member room_no. Print all using the function print_details(). Also get the total no. 
  Of hostelers and day scholars using static variables and methods*/
import java.util.Scanner;
class Student{
    int rno;
    String name;
    Student(int rno, String name){
        this.rno = rno;
        this.name = name;
    }
}
class Day_Scholar extends Student{
    int bus_no;
    Day_Scholar(int rno, String name,int bus){
        super(rno,name);
        this.bus_no = bus;
    }
    void print_details(){
        System.out.println("Name : "+name+" bus_no : "+bus_no);
    }
}
class Hosteler extends Student{
    int room_no;
    Hosteler(int rno,String name,int room){
        super(rno,name);
        this.room_no = room;
    } 
    void print_details(){
        System.out.println("Name : "+name+" room_no : "+room_no);
    }
}
public class College {
    static int hostelers=0;
    static int dayScholar=0;
    public static void main(String[] args){
        Day_Scholar[] d = new Day_Scholar[10];
        Hosteler[] h = new Hosteler[10];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of students : ");
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            System.out.println("Hosteler(1) or Day_Scholar(0) ");
            int c = sc.nextInt();
            if(c==0){
                dayScholar++;
                System.out.println("Enter roll_no,name and bus no ");
                int no = sc.nextInt();
                sc.nextLine();
                String names = sc.nextLine();
                int bu = sc.nextInt();
                d[dayScholar] = new Day_Scholar(no,names,bu);
            }
            if(c==1){
                hostelers++;
                System.out.println("Enter roll_no,name and hosetl no ");
                int no = sc.nextInt();
                sc.nextLine();
                String names = sc.nextLine();
                int b = sc.nextInt();
                h[hostelers] = new Hosteler(no,names,b);
            }
        }
        System.out.println("Hostelers : "+hostelers+" Day Scholars : "+dayScholar);
        System.out.println("Details of dayScholar \n");
        for(int i=1;i<=dayScholar;i++)
            d[i].print_details();
        System.out.println("Details of hostlers \n");
        for(int i=1;i<=hostelers;i++)
            h[i].print_details();
    }
}
