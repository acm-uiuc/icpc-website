#include <iostream>

using namespace std;

int main () {
	int n;
	while (1) {
		cin >> n;
		if (n == -1) break;
		int ans = 0;
		int prev_time = 0;
		for (int i = 0; i < n; i ++) {
			int v, t;
			cin >> v >> t;
			ans += v * (t - prev_time);
			prev_time = t;
		}
		cout << ans << " miles" << endl;
	}
	return 0;
}

