import java.util.*;

public class A02_114502540 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        boolean[][] pre = new boolean[101][101];
        while (sc.hasNextInt()) 
        {
            int sx = sc.nextInt(), sy = sc.nextInt();
            char d = sc.next().charAt(0);
            String cmd = sc.next();
            boolean flag = false;
            for (int i = 0; i < cmd.length(); i++) 
            {
                char c = cmd.charAt(i);
                if (c == 'F') 
                {
                    switch (d) 
                    {
                        case 'N': sy++; break;
                        case 'E': sx++; break;
                        case 'W': sx--; break;
                        case 'S': sy--; break;
                    }
                } 
                else if (c == 'R') 
                {
                    switch (d) 
                    {
                        case 'N': d = 'E'; break;
                        case 'E': d = 'S'; break;
                        case 'W': d = 'N'; break;
                        case 'S': d = 'W'; break;
                    }
                } 
                else 
                {
                    switch (d) 
                    {
                        case 'N': d = 'W'; break;
                        case 'E': d = 'N'; break;
                        case 'W': d = 'S'; break;
                        case 'S': d = 'E'; break;
                    }
                }
                if (sx < 0 || sy < 0 || sx > n || sy > m) 
                {
                    switch (d) 
                    {
                        case 'N': sy--; break;
                        case 'E': sx--; break;
                        case 'W': sx++; break;
                        case 'S': sy++; break;
                    }
                    if (pre[sx][sy]) continue;
                    flag = true;
                    pre[sx][sy] = true;
                    break;
                }
            }
            if (!flag) System.out.printf("%d %d %c%n", sx, sy, d);
            else System.out.printf("%d %d %c LOST%n", sx, sy, d);
        }
    }
}
