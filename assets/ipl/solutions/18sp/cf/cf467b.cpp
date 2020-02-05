#include <iostream>
#include <vector>

using namespace std;

int diff (int p, int q) {
	int cnt = 0;
	while (p || q) {
		if ((p & 1) != (q & 1)) cnt++;
		p >>= 1; q >>= 1;
	}
	return cnt;
}

int main () {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(m+1);
	for (int i = 0; i <= m; i++) cin >> a[i];
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (diff(a[i], a[m]) <= k) ans++;
	}
	cout << ans << endl;
	return 0;
}

