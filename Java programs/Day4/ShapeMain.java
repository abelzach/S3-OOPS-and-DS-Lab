abstract class Shape{
	abstract void Number_of_Sides();
}
class Triangle extends Shape{
	void Number_of_Sides(){
		System.out.println("Number of sides of a Triangle is 3");
	}
}
class Rectangle extends Shape{
	void Number_of_Sides(){
		System.out.println("Number of sides of a Rectangle is 4");
	}
}
class Hexagon extends Shape{
	void Number_of_Sides(){
		System.out.println("Number of sides of a Hexagon is 6");
	}
}
class ShapeMain{
	public static void main(String[] args) {
		Shape r;
		Triangle tri=new Triangle();
		Rectangle rect=new Rectangle();
		Hexagon hex=new Hexagon();
		r=tri;
		r.Number_of_Sides();
		r=rect;
		r.Number_of_Sides();
		r=hex;
		r.Number_of_Sides();
	}
}