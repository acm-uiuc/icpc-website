#include <iostream>

using namespace std;

int main () {
	int n;
	for (int tt = 1; ; tt++) {
		cin >> n;
		if (n < 0) break;
		int ans = 0, tmp = 1;
		while (tmp < n) {
			tmp *= 2;
			ans++;
		}
		cout << "Case " << tt << ": " << ans << endl;
	}
	return 0;
}

