import java.util.Scanner;
import java.util.ArrayList;

public class A022_114502540
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        int[] baseValue = new int[N], GOE = new int[N];
        for(int i=0; i<N; ++i) baseValue[i] = s.nextInt();
        for(int i=0; i<N; ++i) GOE[i] = s.nextInt();

        int fall = 0; boolean isComb = false;
        ArrayList<Double> score = new ArrayList<>();

        for(int i=0; i<N; ++i)
        {
            if(baseValue[i] == -1) ++fall;
            else
            {
                if(baseValue[i] == 0) isComb = true;
                else
                {
                    double single = baseValue[i] + baseValue[i] * GOE[i] * 0.1;
                    if(isComb) 
                    {
                        score.set(score.size()-1, score.get(score.size()-1) + single);
                        isComb = false;
                    }
                    else score.add(single);
                }
            }
        }

        double reward = 0;
        for(int i=0; i<3 && !score.isEmpty(); ++i) reward += score.remove(score.size() - 1);
        score.add(reward * 1.1);

        double sum = 0;
        for(double i:score) sum += i;
        System.out.printf("%.1f%n",sum - fall);
    }
}