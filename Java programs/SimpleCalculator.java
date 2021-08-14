import javax.swing.*;
import java.awt.*;
import java.awt.event.*;  
public class SimpleCalculator implements ActionListener{
    JFrame frame = new JFrame("CALCULATOR");
	JButton b1=new JButton ("1");
	JButton b2=new JButton ("2");
	JButton b3=new JButton ("3");
	JButton b4=new JButton ("4");
	JButton b5=new JButton ("5");
	JButton b6=new JButton ("6");
	JButton b7=new JButton ("7");
	JButton b8=new JButton ("8");
	JButton b9=new JButton ("9");
	JButton b10=new JButton ("0");
	JButton ba=new JButton ("+");
	JButton bs=new JButton ("-");
	JButton bm= new JButton ("x");
	JButton bd= new JButton ("/");
	JButton be= new JButton ("=");
	JButton bf=new JButton(".");
	JButton clear = new JButton ("CE");
	JButton delete = new JButton ("Del");
	JButton r1 = new JButton("On");    
	JButton r2 = new JButton("Off"); 
	JTextField text = new JTextField();
	JTextField text2 = new JTextField();
	
	char operator;
	double num1=0,num2=0,result=0;
	int flag = 0;

    SimpleCalculator(){
		r1.setEnabled(false);
        
        text.setBounds(26,40,285,78);
		text.setFont(new Font("Arial", Font.BOLD, 30));
		frame.add(text);
		
		text2.setBounds(230,10,80,25);
		text2.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(text2);
        
        b1.setBounds(30,300,67,47);
		b1.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b1);
		b1.addActionListener(this);
		        
        b2.setBounds(100,300,67,47);
	   	b2.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b2);
		b2.addActionListener(this);
			
		b3.setBounds(170, 300,67, 47);
		b3.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b3);
		b3.addActionListener(this);

		b4.setBounds(30,250,67,47);
		b4.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b4);
		b4.addActionListener(this);

		b5.setBounds(100, 250,67, 47);
		b5.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b5);
		b5.addActionListener(this);
	
		b6.setBounds(170,250,67,47);
		b6.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b6);
		b6.addActionListener(this);
		
		b7.setBounds(30,200,67,47);
		b7.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b7);
		b7.addActionListener(this);
		
		b8.setBounds(100, 200,67, 47);
		b8.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b8);
		b8.addActionListener(this);

		b9.setBounds(170,200,67,47);
		b9.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b9);
		b9.addActionListener(this);
			
		b10.setBounds(100,350,67,47);
		b10.setFont(new Font("Arial", Font.BOLD, 20));
		frame.add(b10);
		b10.addActionListener(this);

		clear.setBounds(30,140,100,52);
		clear.setFont(new Font("Arial", Font.BOLD, 20));
		clear.setBackground(Color.LIGHT_GRAY);
		frame.add(clear);
		clear.addActionListener(this);

		delete.setBounds(135,140,100,52);
		delete.setFont(new Font("Arial", Font.BOLD, 20)) ;
		delete.setBackground(Color.LIGHT_GRAY);
		frame.add(delete);
		delete.addActionListener(this);

		bf.setBounds(30,350,67,47);
		bf.setFont (new Font("Arial", Font.BOLD, 20));
		frame.add(bf);
		bf.addActionListener(this);

		ba.setBounds(245,250,60,47);
		ba.setFont (new Font("Arial", Font.BOLD, 25));
		ba.setBackground(Color.gray);
		frame.add(ba);
		ba.addActionListener(this);
	
		bs.setBounds(245,300,60,47);
		bs.setFont (new Font("Arial", Font.BOLD, 25));
		bs.setBackground(Color.gray);
		frame.add(bs);
		bs.addActionListener(this);
	
		bm.setBounds(245,350,60,47);
		bm.setFont (new Font("Arial", Font.BOLD, 25));
		bm.setBackground(Color.gray);
		frame.add(bm);
		bm.addActionListener(this);

		bd.setBounds(245,200,60,47);
		bd.setFont (new Font("Arial", Font.BOLD, 25));
		bd.setBackground(Color.gray);
		frame.add(bd);
		bd.addActionListener(this);
				
		be.setBounds(170,350,67, 47);
		be.setFont (new Font("Arial", Font.BOLD, 20));
		frame.add(be);
		be.addActionListener(this);
	
		r1.setBounds(245,140,60,25);
		frame.add(r1);
        r1.addActionListener(this);
  
		r2.setBounds(245,163,60,25);
		frame.add(r2);

        r2.addActionListener(this);

        frame.setSize(360,480);
		frame.getContentPane().setLayout(null);
		frame.getContentPane().setBackground(Color.black);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public void actionPerformed(ActionEvent e) throws ArithmeticException {
		if(e.getSource() == b1)
		{
			text.setText(text.getText().concat("1"));
			flag = 1;
		}
		else if(e.getSource() == b2){
			text.setText(text.getText().concat("2"));
			flag = 1;
		}
		else if(e.getSource() == b3){
			text.setText(text.getText().concat("3"));
			flag = 1;
		}
		else if(e.getSource() == b4){
			text.setText(text.getText().concat("4"));
			flag = 1;
		}
		else if(e.getSource() == b5){
			text.setText(text.getText().concat("5"));
			flag = 1;
		}
		else if(e.getSource() == b6){
			text.setText(text.getText().concat("6"));
			flag = 1;
		}	
		else if(e.getSource() == b7){
			text.setText(text.getText().concat("7"));
			flag = 1;
		}
		else if(e.getSource() == b8){
			text.setText(text.getText().concat("8"));
			flag = 1;
		}
		else if(e.getSource() == b9){
			text.setText(text.getText().concat("9"));
			flag = 1;
		}
		else if(e.getSource() == b10)
			text.setText(text.getText().concat("0"));
		else if(e.getSource() == clear)
		{
			text.setText("");
			text2.setText("");	
		}	
		else if(e.getSource() == delete)
		{
			String s = text.getText();
			text.setText("");
			for(int i=0;i<s.length()-1;i++)
				text.setText(text.getText()+s.charAt(i));
		}
		else if(e.getSource() == bf)
			text.setText(text.getText().concat("."));
		else if(e.getSource() == ba)
		{
			num1 = Double.parseDouble(text.getText());
			operator = '+';
			text2.setText(String.valueOf(num1));
			text.setText("");
		}
		else if(e.getSource() == bs)
		{
			if(flag == 0){
				text.setText(text.getText().concat("-"));
			}
			else if(flag == 1)
			{
				num1 = Double.parseDouble(text.getText());
				operator = '-';
				text2.setText(String.valueOf(num1));
				text.setText("");
			}
		}
		else if(e.getSource() == bm)
		{
			num1 = Double.parseDouble(text.getText());
			operator = '*';
			text2.setText(String.valueOf(num1));
			text.setText("");
		}
		else if(e.getSource() == bd)
		{
			num1 = Double.parseDouble(text.getText());
			operator = '/';
			text2.setText(String.valueOf(num1));
			text.setText("");
		}
		
		else if(e.getSource() == be)
		{
			try{
				text2.setText("");
				num2 = Double.parseDouble(text.getText());
				switch(operator){
					case '+':result = num1+num2;
							break;
					case '-':result = num1-num2;
							break;
					case '*':result = num1*num2;
							break;
					case '/':if(num2 == 0)
								throw new ArithmeticException("Infinity");
							result = num1/num2;
							break;
				}
				text.setText(String.valueOf(result));
				num1 = result;
				flag = 0;
				
			}catch(ArithmeticException ex){
				text.setText("Exception : "+ex);
			}
			catch(Exception ex){
				text.setText("Exception : "+ex);
			}
		}
	
		else if(e.getSource() == r1)
		{
			b1.setEnabled(true);
			b2.setEnabled(true);
			b3.setEnabled(true);
			b4.setEnabled(true);
			b5.setEnabled(true);
			b6.setEnabled(true);
			b7.setEnabled(true);
			b8.setEnabled(true);
			b9.setEnabled(true);
			b10.setEnabled(true);
			ba.setEnabled(true);
			bm.setEnabled(true);
			bf.setEnabled(true);
			bs.setEnabled(true);
			be.setEnabled(true);
			bd.setEnabled(true);
			clear.setEnabled(true);
			delete.setEnabled(true);
			r2.setEnabled(true);
			r1.setEnabled(false);
		}
		else if(e.getSource() == r2)
		{
			b1.setEnabled(false);
			b2.setEnabled(false);
			b3.setEnabled(false);
			b4.setEnabled(false);
			b5.setEnabled(false);
			b6.setEnabled(false);
			b7.setEnabled(false);
			b8.setEnabled(false);
			b9.setEnabled(false);
			b10.setEnabled(false);
			ba.setEnabled(false);
			bm.setEnabled(false);
			bs.setEnabled(false);
			be.setEnabled(false);
			bf.setEnabled(false);
			bd.setEnabled(false);
			clear.setEnabled(false);
			delete.setEnabled(false);
			r2.setEnabled(false);
			r1.setEnabled(true);
		}
	}
            
    public static void main(String[] args){
        new SimpleCalculator();
    }
}
