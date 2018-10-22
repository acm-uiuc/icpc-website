import java.io.*;
import java.util.*;

// Boxes
// runtime: 0.270 / 3.000 [No fast IO used]
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int N = sc.nextInt();
            if (N == 0) return;
            int[] dp = new int[3001];
            int[][] box = new int[N][2];
            for (int i = 0; i < N; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                box[i][0] = a;
                box[i][1] = b;
            }

            for (int i = 0; i < N; i++) {
                int[] nextDp = Arrays.copyOf(dp, dp.length);
                int curWeight = box[i][0];
                int load = box[i][1];
                nextDp[load] = Math.max(1, nextDp[load]);
                for (int j = curWeight; j <= 3000; j++) {
                    if (dp[j] >= 1) {
                        int canLoad = Math.min(load, j - curWeight);
                        nextDp[canLoad] = Math.max(nextDp[canLoad], dp[j] + 1);
                    }
                }
                dp = nextDp;
            }
            int max = 0;
            for (int i = 0; i <= 3000; i++) {
                max = Math.max(max, dp[i]);
            }
            System.out.println(max);
        }
    }
}