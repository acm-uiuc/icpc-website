#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long ans = (long long) n * (n+1) / 2;
		int max_pow_2 = 1;
		while (max_pow_2 * 2 <= n) max_pow_2 *= 2;
		ans -= (max_pow_2 * 2 - 1) * 2;
		cout << ans << endl;
	}
	return 0;
}

