import java.util.*;

public class Q1
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine())
        {
            String s = sc.next(), ss = s;
            if(s.equals("0")) break;
            int cnt = 0, sum;
            do {
                sum = 0;
                for(char i : s.toCharArray()) sum += i - '0';
                s = String.valueOf(sum);
                ++cnt;
            } while (sum >= 10);
            if(s.equals("9")) System.out.printf("%s is a multiple of 9 and has 9-degree %d.%n", ss, cnt);
            else System.out.printf("%s is not a multiple of 9.%n", ss);
        }
        sc.close();
    }
}