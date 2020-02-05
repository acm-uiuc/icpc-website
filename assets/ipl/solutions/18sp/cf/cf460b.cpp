#include <iostream>
#include <vector>

using namespace std;

int s (int x) {
	int ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int pow (int base, int p) {
	int ans = 1;
	while (p--) ans *= base;
	return ans;
}

int main () {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> ans;
	for (int i = 1; i <= 81; i ++) {
		long long x = (long long)b * pow(i, a) + c;
		if ((int)(x) != x) continue;
		if (s(x) == i && x < 1e9) ans.push_back(x);
	}
	cout << ans.size() << endl;
	for (int i : ans) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}

