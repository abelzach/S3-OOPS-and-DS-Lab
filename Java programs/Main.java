import java.util.Scanner;
class DoublyLinked{
	class Node {
		int data;
		Node llink;
		Node rlink;
		public Node(int item){
			data = item;
		}
	}
	Node head,temp = null;
	public void addNode(int item){
		Node newNode = new Node(item);
		if(head == null){
			head = newNode;
			temp = head;
			head.rlink = null;
			head.llink = null;
		}
		else{
			temp.rlink = newNode;
			newNode.llink = temp;
			temp = temp.rlink;
			temp.rlink = null;
		}
	}
	public void deleteNode(int item){
        	Node current;
        	if(head == null)
            {
                System.out.println("Empty");
                return;
            }
            if (head.data == item){
                head = head.rlink;
                return;
            }
            current = head.rlink;
        	while(current != null)
        	{
            	if(current.data == item)
                {
                    (current.llink).rlink = current.rlink;
                    if(current.rlink != null){
                        (current.rlink).llink = current.llink;
                    }
                }
                current = current.rlink;
        	}
	}
	public void display(){
		Node current = head;
		if(head == null)
			System.out.println("Doubly linked list is empty");
		else{
			while(current != null){
				System.out.print(current.data+" ");
				current = current.rlink;
			}
		}
	}
}
class Main{
	public static void main(String[] args){
	char ch;
	Scanner sc = new Scanner(System.in);
	DoublyLinked dl = new DoublyLinked();
	System.out.println("\n\t\tMENU \n 1)Add element \n 2)Delete element \n 3)Display element ");
	do{
		System.out.println("\n Enter your choice : ");
		int c = sc.nextInt();
		if(c == 1){
			System.out.println("Enter element to insert : ");
			int t = sc.nextInt();
			dl.addNode(t);
			System.out.println("Linked list : ");
			dl.display();
		}
		else if(c == 2){
			System.out.println("Enter element to delete: ");
			int t = sc.nextInt();
			dl.deleteNode(t);
			System.out.println("Linked list : ");
			dl.display();
		}
		else if(c == 3)
			dl.display();
		System.out.println("\n Do you want to continue?(y/n) : ");
		ch = sc. next().charAt(0);
	}while(ch == 'y' || ch == 'Y');
	}
}
