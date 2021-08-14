import java.io.*;
import javax.swing.*;
import java.awt.event.*;
class Customer implements Serializable{
	String cid;
	int m[]=new int[6];
	Customer(){
	}
	Customer(String custid,int a[])
	{
		cid = custid;
		for(int i=0;i<6;i++)
			m[i]=a[i];
	}
}
class Swing extends JFrame implements ActionListener{
JButton submit= new JButton("SUBMIT");
JButton calculate = new JButton("CALCULATE");
JTextField id= new JTextField("Customer ID");
JTextField m1= new JTextField("Month 1");
JTextField m2= new JTextField("Month 2");
JTextField m3= new JTextField("Month 3");
JTextField m4= new JTextField("Month 4");
JTextField m5= new JTextField("Month 5");
JTextField m6= new JTextField("Month 6");
JTextField m7= new JTextField("Month 7");
Swing(){
this.setSize(300,700);
id.setBounds(100,50,100,40);
add(id);
m1.setBounds(100,150,100,40);
add(m1);
m2.setBounds(100,200,100,40);
add(m2);
m3.setBounds(100,250,100,40);
add(m3);
m4.setBounds(100,300,100,40);
add(m4);
m5.setBounds(100,350,100,40);
add(m5);
m6.setBounds(100,400,100,40);
add(m6);
submit.setBounds(40,500,100,40);
add(submit);
submit.addActionListener(this);
calculate.setBounds(80,550,100,40);
add(calculate);
calculate.addActionListener(this);
m7.setBounds(30,600,220,40);
add(m7);
this.setLayout(null);
this.setVisible(true);
this.setDefaultCloseOperation(this.EXIT_ON_CLOSE);
}
public void actionPerformed(ActionEvent e){
if(e.getSource() == submit){
String idd = id.getText();
int a[] = new int[6];
a[0] = Integer.parseInt(m1.getText());
a[1] = Integer.parseInt(m2.getText());
a[2] = Integer.parseInt(m3.getText());
a[3] = Integer.parseInt(m4.getText());
a[4] = Integer.parseInt(m5.getText());
a[5] = Integer.parseInt(m6.getText());
Customer c = new Customer(idd,a);
try{
FileOutputStream fout= new FileOutputStream("inputfile.txt");
ObjectOutputStream out= new ObjectOutputStream(fout);
out.writeObject(c);
out.close();
fout.close();
}catch(Exception ex){
System.out.println(ex);
}
}
if(e.getSource() == calculate){
try{
	FileInputStream fin= new FileInputStream("inputfile.txt");
	ObjectInputStream in= new ObjectInputStream(fin);
	Customer a = (Customer)in.readObject();
	float avg = 0;
	for(int i=0;i<6;i++)
		avg+=a.m[i];
	in.close();
	fin.close();
	avg = avg/6;
	m7.setText(String.valueOf(avg));
}catch(Exception ex){
System.out.println(ex);
}
}
}

public static void main(String args[]){
new Swing();
}
}