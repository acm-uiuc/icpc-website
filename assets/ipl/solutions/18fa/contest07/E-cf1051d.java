int mod = 998244353;
public long add(long a, long b) {
    return (a + b) % mod;
}

public void solve(Scanner sc, PrintWriter pw) throws IOException {
    int n = sc.nextInt();
    int k = sc.nextInt();
    long[][] dp = new long[k + 4][2];
    if (k == 1) {
        pw.println(2);
        return;
    }
    dp[0][0] = 2; // 0 -> two colors in the column are same
    dp[0][1] = 2; // 1 -> different
    for (int i = 0; i < n - 1; i++) {
        long[][] cp = new long[k + 4][2];
        for (int j = 0; j <= k; j++) {
            cp[j][0] = add(cp[j][0], dp[j][0]);
            cp[j][1] = add(cp[j][1], add(dp[j][0], dp[j][0]));
            cp[j + 1][0] = add(cp[j + 1][0], dp[j][0]);

            cp[j][1] = add(cp[j][1], dp[j][1]);
            cp[j + 1][0] = add(cp[j + 1][0], add(dp[j][1], dp[j][1]));
            cp[j + 2][1] = add(cp[j + 2][1], dp[j][1]);
        }
        dp = cp;
    }
    long result = add(dp[k - 1][0], dp[k - 2][1]);
    pw.println(result);
}