#include <iostream>
#define LL long long
#define MOD 998244353

using namespace std;

LL dp[1001][2001][4];

int main () {
	int n, k; cin >> n >> k;
	dp[0][1][0] = dp[0][1][3] = 1;
	dp[0][2][1] = dp[0][2][2] = 1;
	for (int x = 1; x < n; x++) {
		for (int y = 1; y <= 2000; y++) {
			dp[x][y][0] = (dp[x-1][y][0] + dp[x-1][y][1] + dp[x-1][y][2] + dp[x-1][y-1][3]) % MOD;
			dp[x][y][1] = (dp[x-1][y-1][0] + dp[x-1][y][1] + (y == 1 ? 0 : dp[x-1][y-2][2]) + dp[x-1][y-1][3]) % MOD;
			dp[x][y][2] = (dp[x-1][y-1][0] + (y == 1 ? 0 : dp[x-1][y-2][1]) + dp[x-1][y][2] + dp[x-1][y-1][3]) % MOD;
			dp[x][y][3] = (dp[x-1][y-1][0] + dp[x-1][y][1] + dp[x-1][y][2] + dp[x-1][y][3]) % MOD;
		}
	}
	LL ans = (dp[n-1][k][0] + dp[n-1][k][1] + dp[n-1][k][2] + dp[n-1][k][3]) % MOD;
	cout << ans << endl;

	return 0;
}
