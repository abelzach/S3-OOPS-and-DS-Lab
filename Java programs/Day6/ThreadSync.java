import java.util.*;
class Stack{
	int a[]=new int[5];
	int top=-1;
	public synchronized void push() throws Exception
  	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter the element to push : ");
		top+=1;
		a[top]=sc.nextInt();
		System.out.println("Pushed "+a[top]+" into the stack");
	}
	public synchronized void pop() throws Exception
  	{
		System.out.println("Popped "+a[top]+" from the stack");
		top--;		
	}
}
class Producer implements Runnable{
	Stack t;

	Producer(Stack t){
		this.t=t;
	}
	public void run(){
		int n=5;
		try{

			for(int i=0;i<n;i++){
				t.push();
			}
			if(t.top == n-1){
				System.out.println("Producer waiting");
				wait();
			}
			notify();
		}catch(Exception e){
      System.out.println("Exception : "+e);
    }
	}
}
class Consumer implements Runnable{
	Stack t;
	Consumer(Stack t){
		this.t=t;
	}
	public void run(){
		try{
			while(t.top!=-1)
      		{
				t.pop();
				try{Thread.sleep(1000);}
			catch(Exception e){
			System.out.println("Exception : "+e);
        	}
			}
			if(t.top==-1){
				System.out.println("Consumer waiting");
				wait();
			}
			notify();
		}catch(Exception e){
      System.out.println("Exception : "+e);
    }
	}
}
public class ThreadSync{
	public static void main(String[] args) {
		Stack t=new Stack();
		Producer p= new Producer(t);
		Consumer c= new Consumer(t);
		Thread tp=new Thread(p);
		Thread tc=new Thread(c);
		System.out.println("\nPushing to stack");
		tp.start();
		try{
			tp.join();
		}catch(Exception e){
      System.out.println("Exception : "+e);
      }
		System.out.println("\nPopping from stack");
		tc.start();
	}
}