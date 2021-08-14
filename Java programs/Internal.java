import java.util.*;
import java.util.Scanner;
class Natural extends Thread{
	public void run(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter value of n : ");
		int n = sc.nextInt();
		System.out.println("The natural numbers are : ");
		for(int i=0;i<=n;i++)
			System.out.println(i);
	}
}
class Armstrong extends Thread{
	int sum=0,r=0,m,t;
	String s;
	Armstrong(String s){
		this.s = s;
	}
	int num = Integer.parseInt(s);
	int l = s.length();
	public void run(){
		m = num;	
		while(m!=0){
			t=1;
			r = m%10;
			for(int i=0;i<l;i++)
				t*=m;
			sum+=t;
			m=m/10;
		}
		if(num == sum)
			System.out.println(num+" is an armstrong number");
		else
			System.out.println("Not armstrong");
	}
}

public class Internal{
	public static void main(String args[]){
		Natural na = new Natural();
		na.start();
		try{
			na.join();
		}catch(Exception e){
			System.out.println(e);
		}
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number : ");
		String s = sc.nextLine();
		Armstrong a = new Armstrong(s);
		a.start();
	}
}