#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int n, k, d;
	cin >> n >> k >> d;
	if (log(n) / log(k) > d + 1e-08) {
		cout << -1 << endl;
	} else {
		long long base = 1;
		for (int i = 0; i < d; i ++) {
			int out = 0;
			for (int j = 0; j < n; j ++) {
				if (j % base == 0) out = out % k + 1;
				cout << out << ' ';
			}
			base = min((long long)0x7fffffff, base * k);
			cout << endl;
		}
	}

	return 0;
}

