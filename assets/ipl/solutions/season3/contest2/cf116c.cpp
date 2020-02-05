#include <iostream>

using namespace std;

int p[2001];
int dep[2001];

int calc_dep(int i) {
	if (i == -1) return 0;
	if (dep[i]) return dep[i];
	return dep[i] = calc_dep(p[i]) + 1;
}

int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> p[i];
	for (int i = 1; i <= n; i ++) {
		calc_dep(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) ans = max(ans, dep[i]);
	cout << ans << endl;
	return 0;
}

