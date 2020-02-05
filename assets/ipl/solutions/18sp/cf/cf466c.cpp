#include <iostream>
#include <vector>
#define LL long long

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> a(n);
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	vector<int> pts;
	int cnt1 = 0, cnt2 = 0;
	LL acc = 0;
	for (int i = 0; i < n-1; i++) {
		acc += a[i];
		// this order is critical because we don't want i=j
		if (3 * acc == 2 * sum) { pts.push_back(2); cnt2++; }
		if (3 * acc == sum) { pts.push_back(1); cnt1++; }
	}
	LL ans = 0;
	for (int p : pts) {
		if (p == 1) ans += cnt2;
		else cnt2--;
	}
	cout << ans << endl;

	return 0;
}

