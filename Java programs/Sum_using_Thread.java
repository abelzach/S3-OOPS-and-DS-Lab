class ThreadDemo2 extends Thread {

    int [] array = new int [100];
    int sum = 0;
    int max = Integer.MIN_VALUE;

    ThreadDemo2(int [] a) {
        array = a;
    }
    public void run()
    {
        for(int i = 0; i < array.length; i++)
        {
            System.out.print(array[i] + " ");
            sum += array[i];
            if(max < array[i])
            {
                max = array[i];
            }
        }
        System.out.println("");
        System.out.println("Max : " + max);
        System.out.println("Sum : " + sum);
    }

}

public class Sum_using_Thread {
    public static void main(String[] args) {
        
    int[] a = {20 , 20, 34 , 456 , 56};
    ThreadDemo2 th = new ThreadDemo2(a);
    th.start(); 
    }
}