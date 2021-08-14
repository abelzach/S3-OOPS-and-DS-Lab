import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Buttons{
    public static void main(String[] args) //main function
{
        // container - JFrame
        // Component -  JButton , JLabel
        JFrame f = new JFrame("Toggle Button");  
        
        
        // Set new name for button
        JToggleButton b1 = new JToggleButton();
        b1.setText("OFF");
        
        // Set boundary for Button
        // b1.setBounds(x-axis , y-axis , width , height);
        b1.setBounds(130,100,150, 50);
        
        // Add Label 
        JLabel jl  = new JLabel("Please Click here ");
        
        jl.setBounds(130,50,150,40);

	JTextField t2 = new JTextField("Adress");
	t2.setBounds(130,150,150,40);
        ItemListener il = new ItemListener() 
        { 
          public void itemStateChanged(ItemEvent ie) {
              if(b1.isSelected())
              b1.setText("ON");
              else
              b1.setText("OFF");
            }
        };
        // Add components
        b1.addItemListener(il);
        f.add(b1);
        f.add(jl);
	f.add(t2);
    
        // Size of the frame
        f.setSize(400 , 400);
    
        f.setLayout(null);
        f.setVisible(true);
   }    
}