#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define LL long long

using namespace std;



int main () {
	vector<int> coins {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	vector<vector<LL>> dp(12, vector<LL>(30001, 0));
	for (int i = 0; i < 12; i++) dp[i][0] = 1;
	for (int i = 1; i < coins.size(); i++) {
		for (int j = 1; j <= 30000; j++) {
			for (int k = 0; k * coins[i] <= j; k++) {
				dp[i][j] += dp[i-1][j-k*coins[i]];
			}
		}
	}
	double n;
	while (cin >> n && n) {
		printf("%6.2f%17lld\n", n, dp[11][int(round(100*n))]);
	}

	return 0;
}

