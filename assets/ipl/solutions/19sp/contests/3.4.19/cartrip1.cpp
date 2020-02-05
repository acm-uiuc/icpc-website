#include <bits/stdc++.h>

using namespace std;

int dp[101][101]; // dp[i][j] is the min money to arrive city i with j fuel

int main () {
  int n, v;
  cin >> n >> v;
  vector<int> p(n+1);
  for (int i = 1; i <= n; i++) cin >> p[i];
  // dp[i][j] = dp[i-1][j+1-k] + k * p[i-1]
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= v; j++) {
      dp[i][j] = 0x3fffffff;
    }
  }
  dp[1][0] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < v; j++) {
      dp[i][j] = 0x3fffffff;
      for (int k = 0; k <= j+1; k++) {
        dp[i][j] = min(dp[i][j], dp[i-1][j+1-k] + k * p[i-1]);
      }
    }
  }
  cout << dp[n][0] << endl;

  return 0;
}
