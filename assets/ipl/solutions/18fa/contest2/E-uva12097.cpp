#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double PI = acos(-1.0);



int main () {
	int t; cin >> t;
	while (t--) {
		int n, f; cin >> n >> f;
		vector<double> a(n);
		for (int i = 0; i < n; i++) {
			double r; cin >> r;
			a[i] = PI * r * r;
		}
		double lo = 1e-4, hi = 1e9;
		while (hi - lo > 1e-5) {
			double mi = (lo + hi) / 2;
			int cnt = 0;
			for (int i = 0; i < n; i++) cnt += (int)(a[i] / mi);
			if (cnt >= f + 1) lo = mi;
			else hi = mi;
		}
		cout << setiosflags(ios::fixed) << setprecision(4) << lo << endl;
	}

	return 0;
}

