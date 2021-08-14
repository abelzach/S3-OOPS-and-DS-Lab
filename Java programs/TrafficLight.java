import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TrafficLight extends JFrame implements ActionListener{
	JRadioButton rb1= new JRadioButton("RED");
	JRadioButton rb2= new JRadioButton("YELLOW");
	JRadioButton rb3= new JRadioButton("GREEN");
	ButtonGroup b = new ButtonGroup();
	TrafficLight(){
		setTitle("TRAFFIC LIGHT");
		setSize(500,550);
		rb1.setBounds(270,100,150,40);
		rb2.setBounds(270,150,150,40);
		rb3.setBounds(270,200,150,40);
		b.add(rb1);
		b.add(rb2);
		b.add(rb3);
        add(rb1);
		add(rb2);
		add(rb3);		
        rb1.addActionListener(this);
        rb2.addActionListener(this);
        rb3.addActionListener(this);
		setLayout(null);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		
	}
	public void paint(Graphics g){
		g.drawRect(130,80,115,270);
		g.setColor(Color.BLACK);
		g.fillRect(130,80,115,270);

		g.drawRect(172,350,31,100);
		g.setColor(Color.BLACK);
		g.fillRect(172,350,31,100);

		g.setColor(Color.BLACK);
        g.drawOval(150,100,70,70);
		g.fillOval(150,100,70,70);

		g.setColor(Color.BLACK);
        g.drawOval(150,180,70,70);
		g.fillOval(150,180,70,70);

		g.setColor(Color.BLACK);
        g.drawOval(150,260,70,70);
		g.fillOval(150,260,70,70);
	}
	public void actionPerformed(ActionEvent e){
		Graphics g = getGraphics();
		if(rb1.isSelected()){
		
			g.setColor(Color.RED);
			g.drawOval(150,100,70,70);
			g.fillOval(150,100,70,70);

			g.setColor(Color.BLACK);
            g.drawOval(150,180,70,70);
			g.fillOval(150,180,70,70);

			g.setColor(Color.BLACK);
            g.drawOval(150,260,70,70);
			g.fillOval(150,260,70,70);
		}
		else if(rb2.isSelected()){
			
			g.setColor(Color.BLACK);
            g.drawOval(150,100,70,70);
			g.fillOval(150,100,70,70);

			g.setColor(Color.YELLOW);
			g.drawOval(150,180,70,70);
			g.fillOval(150,180,70,70);

			g.setColor(Color.BLACK);
            g.drawOval(150,260,70,70);
			g.fillOval(150,260,70,70);

		}
		else if(rb3.isSelected()){
			
			g.setColor(Color.BLACK);
            g.drawOval(150,100,70,70);
			g.fillOval(150,100,70,70);

			g.setColor(Color.BLACK);
			g.drawOval(150,180,70,70);
            g.fillOval(150,180,70,70);

			g.setColor(Color.GREEN);
			g.drawOval(150,260,70,70);
			g.fillOval(150,260,70,70);
		}
	}
	public static void main(String[] args) {
		new TrafficLight();

	}
}