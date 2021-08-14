import java.awt.*;  
import java.awt.event.*;  
public class MouseListenerExample extends Frame implements MouseListener,ActionListener{  
    Label l; 
    TextField tf; 
    MouseListenerExample(){  
        addMouseListener(this);  
        tf=new TextField();  
        tf.setBounds(90,80, 150,20);  
        Button b=new Button("Click Here");  
        b.setBounds(50,100,60,30);  
        l=new Label();  
        l.setBounds(20,50,100,20);  
	b.addActionListener(this); 
        add(l);  
	add(b);
	add(tf);
        setSize(300,300);  
        setLayout(null);  
        setVisible(true);  
        //setDefaultCloseOperation(this.EXIT_ON_CLOSE);
    }
    public void actionPerformed(ActionEvent e){  
        tf.setText("Salaam rocky bhai");  
    }    
    public void mouseClicked(MouseEvent e) {  
        l.setText("Mouse Clicked");  
    }  
    public void mouseEntered(MouseEvent e) {  
        l.setText("Mouse Entered");  
    }  
    public void mouseExited(MouseEvent e) {  
        l.setText("Mouse Exited");  
    }  
    public void mousePressed(MouseEvent e) {  
        l.setText("Mouse Pressed");  
    }  
    public void mouseReleased(MouseEvent e) {  
        l.setText("Mouse Released");  
    }  
    public static void main(String[] args) {  
       new MouseListenerExample();  
   }  
}  