import java.util.*;

// Bitmask Top-down DP
// O(2^n * C)

public class A03_114502540
{
    static int T, target;
    static int[][] fr = new int[10][2];

    static final int[] A = {0,1,1,2};
    static final int[] B = {0,0,1,1};

    static int encodeState(int a, int b)
    {
        if (a == 0) return 0;
        if (b == 0) return 1;
        if (a == 1) return 2;
        return 3;
    }

    // {frame, state, pos} -> {bonus, new state}
    static int[] transition(int[] f, int s, int pos)
    {
        int a = A[s], b = B[s], b1 = f[0], b2 = f[1];
        if (pos == 10) return new int[]{a*b1 + b*b2, 0};
        if (b1 == 10) return new int[]{a*10, encodeState(b+1, 1)};  // Strike
        if (b1+b2 == 10) return new int[]{a*b1 + b*b2, encodeState(1, 0)};  // Spare
        return new int[]{a*b1 + b*b2, 0};  // Open
    }

    static boolean canNonTenth(int[] f)
    {
        if (f[0] == 10) return f[1] == 0;
        return f[0] + f[1] <= 10;
    }

    static boolean canTenth(int[] f)
    {
        if (T > 0) return f[0] == 10 || f[0]+f[1] == 10;
        return true;
    }

    static Set<Integer>[][] dp = new HashSet[1<<10][4];
    static boolean[][] vis = new boolean[1<<10][4];

    static Set<Integer> solve(int mask, int s, int pos)
    {
        if (pos == 11)
        {
            HashSet<Integer> r = new HashSet<>();
            r.add(0);
            return r;
        }
        if (vis[mask][s]) return dp[mask][s];
        vis[mask][s] = true;

        Set<Integer> result = new HashSet<>();
        for (int j = 0; j < 10; j++)
        {
            if ((mask >> j & 1) == 1) continue;
            if (pos == 10 && !canTenth(fr[j])) continue;
            if (pos < 10 && !canNonTenth(fr[j])) continue;

            int[] tr = transition(fr[j], s, pos);
            int bonus = tr[0], ns = tr[1];

            for (int b : solve(mask|(1<<j), ns, pos+1)) result.add(bonus + b);
        }
        dp[mask][s] = result;
        return result;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        target = sc.nextInt();
        T = sc.nextInt();
        int base = T;

        for (int i = 0; i < 10; i++)
        {
            fr[i][0] = sc.nextInt();
            fr[i][1] = sc.nextInt();
            base += fr[i][0] + fr[i][1];
        }

        TreeSet<Integer> scores = new TreeSet<>();
        for (int b : solve(0, 0, 1)) scores.add(base + b);
        if (scores.contains(target)) System.out.println(target + " Yes");
        else
        {
            Integer lower = scores.lower(target);
            Integer upper = scores.higher(target);
            StringBuilder sb = new StringBuilder();
            sb.append(target);
            if (lower != null)
            {
                sb.append(" ");
                sb.append(lower);
            }
            if (upper != null)
            {
                sb.append(" ");
                sb.append(upper);
            }
            System.out.println(sb);
        }
    }
}