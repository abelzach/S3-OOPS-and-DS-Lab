/*Write a java program to implement a queue with the following operations:
a) Insert an element into the queue b) Delete an element from the queue
c) Display elements in the stack queue d) Search for a given element in the queue
e) Find the lowest element in the queue
Create a class Queue with the necessary methods for implementing the above operations*/

import java.util.Scanner;
class Q{
	int queue[] = new int[20];
	int front = -1, rear = -1;
	int max = 6;
	void insert(int item){
		if(rear == max-1)
			System.out.println("Oveflow");
		else if(front == -1)
			front = 0;
		rear = rear+1;
		queue[rear] = item;
	}
	void delete(){
		if(front == -1)
			System.out.println("Underflow");
		else if(front == rear){
			front = -1;
			rear = -1;
		}
		else
			front= front+1;
	}
	void display(){
		if(front == -1)
			System.out.println("Underflow");
		else{
			for(int i=front;i<=rear;i++)
				System.out.println(queue[i]);
		}
	}
	void search(int item){
		int flag = 0;
		for(int i=front;i<=rear;i++)
			if(queue[i] == item){
				System.out.println(item+" present");
				flag = 1;
			}
		if(flag==0)
			System.out.println("Not found");
	}
	void lowest()
	{
		int low = queue[front];
		for(int i=front+1;i<=rear;i++)
			if(queue[i]<low)
				low = queue[i];
		System.out.println(low);
	}
}
class Queue{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int ch;
 		Q que =new Q();
 		do{
 			System.out.println("\nEnter choice \n1.Insert 2.Delete 3.Display "+"\n4.Search 5.Find smallest 6.exit :");
			 ch = sc.nextInt();
 			switch(ch){
 				case 1:int item = sc.nextInt();
					que.insert(item);
 					break;
 				case 2:que.delete();
					 break;
				 case 3:que.display();
 					break;
 				case 4:System.out.println("Enter the element to be searched for :");
 					int items =sc.nextInt();
 					que.search(items);
 					break;
 				case 5:que.lowest();
 					break;
				 case 6:break;
 					default:break;
 			}
 		}while(ch>0&&ch<6); 
	}
}
	