
import java.util.*;

public class A01_114502540 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int teams = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < teams; i++) 
        {
            String str = sc.nextLine();

            int N = Integer.parseInt(str, 10);
            String str_10_Binary = Integer.toBinaryString(N);
            int b1 = count(str_10_Binary);
            
            int N1 = Integer.parseInt(str, 16);
            String str_16_Binary = Integer.toBinaryString(N1);
            int b2 = count(str_16_Binary);

            System.out.println(b1 + " " + b2);
        }

        sc.close();
    }

    private static int count(String str) 
    {
        int count = 0;
        for(int i=0; i<str.length(); i++)
        {
            if(str.charAt(i)=='1') count++;
        }
        return count;
    }
}