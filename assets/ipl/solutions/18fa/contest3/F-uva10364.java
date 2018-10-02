import java.io.*;
import java.util.*;

public class Main {

    static int M;
    static int quarter;
    static int[] dp;
    static int[] arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            M = sc.nextInt();
            arr = new int[M];
            dp = new int[1 << M];
            Arrays.fill(dp, -1);
            int sum = 0;
            for (int j = 0; j < M; j++) {
                arr[j] = sc.nextInt();
                sum += arr[j];
            }
            int res = 0;
            if (sum % 4 == 0) {
                quarter = sum / 4;
                res = dfs(0, 0);
            }
            System.out.println(res == 0 ? "no" : "yes");
        }
    }

    public static int dfs(int sum, int bitmask) {
        if (dp[bitmask] != -1) return dp[bitmask];
        int res = 0;
        if (sum == quarter) {
            if (bitmask == (1 << M) - 1) {
                res = 1;
            } else {
                res = dfs(0, bitmask);
            }
        } else if (sum < quarter) {
            for (int i = 0; i < M; i++) {
                if (((1 << i) & bitmask) == 0) {
                    if (dfs(sum + arr[i], bitmask | (1 << i)) > 0) {
                        res = 1;
                    }
                }
            }
        }
        return dp[bitmask] = res;
    }
}
