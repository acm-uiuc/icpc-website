#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main () {
	int n, k;
	cin >> n >> k;
	vector<int> f(n);
	for (int i = 0; i < n; i++) cin >> f[i];
	sort(f.begin(), f.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < n; i += k) {
		ans += 2 * (f[i] - 1);
	}
	cout << ans << endl;

	return 0;
}

