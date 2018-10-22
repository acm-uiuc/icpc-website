// The Islands
import java.util.*;

public class Main {

    public static class Solution {
        double sol;
        int[] path;

        public Solution(double sol, int[] path) {
            this.sol = sol;
            this.path = path;
        }
    }

    public static double d(int[] a, int[] b) {
        return Math.sqrt(Math.pow(a[0] - b[0], 2) + Math.pow(a[1] - b[1], 2));
    }

    public static void iter(double[][] dist, double[][] dp, int[][][] from, int b1, int b2, int i, int j, int k) {
        double D1 = dp[j][k] + dist[j][i];
        if (b1 != i) {
            if (D1 < dp[i][k]) {
                dp[i][k] = D1;
                from[i][k] = new int[]{j, k};
            }
        }
        double D2 = dp[j][k] + dist[k][i];
        if (b2 != i) {
            if (D2 < dp[j][i]) {
                dp[j][i] = D2;
                from[j][i] = new int[]{j, k};
            }
        }
    }

    public static Solution solve(int n, int b1, int b2, int[][] islands) {
        double[][] dist = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = d(islands[i], islands[j]);
            }
        }
        double[][] dp = new double[n][n];
        int[][][] from = new int[n][n][];
        from[0][0] = new int[]{-1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][0] = 0.0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int k = i - 1;
                iter(dist, dp, from, b1, b2 ,i, j, k);
            }
            for (int k = 0; k < i; k++) {
                int j = i - 1;
                iter(dist, dp, from, b1, b2 ,i, j, k);
            }
        }
        int[] minSo = new int[]{-1, -1};
        double mind = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (dp[i][n - 1] + dist[i][n - 1] < mind) {
                mind = dp[i][n - 1] + dist[i][n - 1];
                minSo = new int[]{i, n - 1};
            }
            if (dp[n - 1][i] + dist[i][n - 1] < mind) {
                mind = dp[n - 1][i] + dist[n - 1][i];
                minSo = new int[]{n - 1, i};
            }
        }
        int[] fromV = new int[n];
        if (minSo[0] != n - 1) {
            fromV[n - 1] = minSo[0];
        } else if (minSo[1] != n - 1) {
            fromV[minSo[1]] = n - 1;
        }
        while (minSo[0] != -1) {
            int[] cameFrom = from[minSo[0]][minSo[1]];
            if (cameFrom[0] == -1) break;
            if (cameFrom[0] != minSo[0]) {
                fromV[minSo[0]] = cameFrom[0];
            } else {
                fromV[cameFrom[1]] = minSo[1];
            }
            minSo = cameFrom;
        }
        int[] sol = new int[n + 1];
        int idx = 0;
        sol[n] = idx;
        for (int i = n - 1; i >= 0; i--) {
            idx = fromV[idx];
            sol[i] = idx;
        }
        return new Solution(mind, sol);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ks = 1;
        while (true) {
            int n = sc.nextInt();
            int b1 = sc.nextInt();
            int b2 = sc.nextInt();
            if (n == 0) break;
            int[][] a = new int[n][2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    a[i][j] = sc.nextInt();
                }
            }
            Solution s = solve(n, b1, b2, a);
            System.out.printf("Case %d: %.2f\n", ks++, s.sol);
            if (s.path[1] != 1) {
                for (int i = 0; i < s.path.length / 2; i++) {
                    int t = s.path[i];
                    s.path[i] = s.path[s.path.length - 1 - i];
                    s.path[s.path.length - 1 - i] = t;
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.print(s.path[i] + " ");
            }
            System.out.println(s.path[n]);
        }
    }

}
