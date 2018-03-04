#include <iostream>
#include <vector>

using namespace std;

int main () {
	int n, m, w;
	cin >> n >> m >> w;
	vector<int> a(n);
	int minn = 0x7fffffff;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	int lo = minn, hi = minn + m + 1;
	while (hi - lo > 1) {
		int mi = lo + (hi - lo) / 2;
		long long days = 0;
		int cover = 0;
		vector<int> st(n);
		for (int i = 0; i < n; i ++) {
			if (i >= w) cover -= st[i-w];
			st[i] = max(0, mi - a[i] - cover);
			days += st[i];
			cover += st[i];
		}
		if (days <= m) lo = mi;
		else hi = mi;
	}
	cout << lo << endl;

	return 0;
}

