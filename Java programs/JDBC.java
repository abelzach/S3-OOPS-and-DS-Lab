import java.sql.*;
public class JDBC {
    public static void main(String[] args){
        Connection conn = null;
        Statement stmt = null;
        try{
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:C:/Users/Abel Simon Zachariah/Desktop/JDBC/Test.db");
            stmt = conn.createStatement();
            // stmt.executeUpdate("CREATE TABLE Student(Roll_no INTEGER primary key, Name TEXT, mark1 INTEGER, mark2 INTEGER, mark3 INTEGER);");
            // System.out.println("Table Student created\n");
            // stmt.executeUpdate("INSERT INTO Student(Roll_no,Name,mark1,mark2,mark3) VALUES (15,'Cody',89,95,92);");
            // stmt.executeUpdate("INSERT INTO Student(Roll_no,Name,mark1,mark2,mark3) VALUES (11,'Jake',90,85,82);");
            // stmt.executeUpdate("INSERT INTO Student(Roll_no,Name,mark1,mark2,mark3) VALUES (34,'Zach',81,88,86);");
            // stmt.executeUpdate("INSERT INTO Student(Roll_no,Name,mark1,mark2,mark3) VALUES (65,'John',87,91,90);");
            // System.out.println("Values added to the table");

            ResultSet rs = stmt.executeQuery("SELECT * FROM Student");
            System.out.println("\n\tTABLE");
            System.out.println("Rollno  Name  Mark 1  Mark 2  Mark 3 \n------------------------------------");
            while(rs.next()){
                int rno = rs.getInt("Roll_no");
                String name = rs.getString("Name");
                int m1 = rs.getInt("mark1");
                int m2 = rs.getInt("mark2");
                int m3 = rs.getInt("mark3");

                System.out.println(rno+"     "+name+"     "+m1+"     "+m2+"     "+m3);
            }   
            ResultSet rst = stmt.executeQuery("SELECT Name,Roll_no,mark1+mark2+mark3 AS 'Total Marks' FROM Student ORDER BY mark1+mark2+mark3 DESC ");
            System.out.println("\nRanklist based on total marks ");
            System.out.println("\nRollno  Name   Total Marks \n--------------------------");
            while(rst.next())
            {
                int rno = rs.getInt("Roll_no");
                String name = rs.getString("Name");
                int t = rs.getInt("Total Marks");
                System.out.println(rno+"      "+name+"      "+t);
            }
            conn.close();
            stmt.close();
        }catch(SQLException e){
            e.printStackTrace();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
}


