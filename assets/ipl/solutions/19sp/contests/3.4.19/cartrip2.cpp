#include <bits/stdc++.h>

using namespace std;

int main () {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, v; cin >> n >> v;
  if (n == 1) { cout << 0 << endl; return 0; }
  vector<int> p(n+1);
  p[0] = 0x3fffffff;
  for (int i = 1; i <= n; i++) cin >> p[i];
  int ans = 0;
  deque<int> mq;
  int l = n-1, r = n-1;
  while (n - l <= v) {
    while (!mq.empty() && mq.back() > p[l]) mq.pop_back();
    mq.push_back(p[l]);
    l--;
    if (l == 0) break;
  }
  while (1) {
    if (mq.empty()) { cout << -1 << endl; return 0; }
    ans += mq.front();
    while (!mq.empty() && mq.back() > p[l]) mq.pop_back();
    mq.push_back(p[l]);
    if (l) l--;
    if (mq.front() == p[r]) mq.pop_front();
    r--;
    if (r == 0) break;
  }
  cout << ans << endl;

  return 0;
}
