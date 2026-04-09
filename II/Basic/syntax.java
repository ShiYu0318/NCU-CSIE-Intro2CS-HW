import java.util.Scanner;
import java.util.Random;
import java.util.ArrayList;

public class syntax 
{
    public static void main(String[] args)
    {
        String s1 = "Hello, ", s2 = "Java!";
        boolean b = true;
        final double PI = 3.1415926;


        System.out.print(s1);
        System.out.println(s2);

        System.out.println(s1.equals(s2));
        System.out.println(s1.concat(s2));
        System.out.printf("%s\n%s", s1, s2);

        
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        Random r = new Random();
        System.out.println(n + r.nextInt(10));


        int[] arr1 = new int[3];
        int[] arr2 = {0,1,2};
        int[][] arr3 = {{1,2,3},{4,5,6},{7,8,9}};

        ArrayList<Integer> arr = new ArrayList<Integer>();
        
        arr.add(1);
        arr.add(2);
        arr.add(3);
        System.out.println(arr);

        arr.set(2, 4);
        System.out.println(arr);

        arr.remove(0);        
        System.out.println(arr);

        arr.remove(Integer.valueOf(2));
        System.out.println(arr);
    }
}
