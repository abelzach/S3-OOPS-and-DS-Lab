import java.io.*;
import java.util.Scanner;
class File{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int i;
    String text="";
    FileOutputStream fout;
    FileInputStream fin;
    try{
        fout = new FileOutputStream("inputfile.txt");
        System.out.println("Enter contents to input file : ");
      String s = sc.nextLine();
        byte b[] = s.getBytes();
        fout.write(b);    
        fout.close(); 
        fout = new FileOutputStream("outputfile.txt");
        fin = new FileInputStream("inputfile.txt");
        do{
            i = fin.read();
            if(i != -1)
              fout.write(i);
          }while(i != -1);
        fout.close();
        fin.close();
        System.out.println("Copied contents of input file to output file");
        System.out.println("Contents of Output file : ");
      
        fin = new FileInputStream("outputfile.txt");
        do{
          i = fin.read();
          if(i != -1)
            text = text+((char)i);
        }while(i != -1);
        fin.close();
        text = text.replaceAll(" ","_");
      }catch(FileNotFoundException e){
        System.out.println("File not found"+e);
      }
      catch(IOException e){
        System.out.println("File Error"+e);
      }
      catch(Exception e)
      {
        System.out.println("Exception "+e);
      }
      finally{
        System.out.println(text);
      }
  }
}