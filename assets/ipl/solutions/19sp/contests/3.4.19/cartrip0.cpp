#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, v; cin >> n >> v;
  int ans = 0;
  for (int i = n; i > 1; i--) {
    ans += max(i-v, 1);
  }
  cout << ans << endl;

  return 0;
}
