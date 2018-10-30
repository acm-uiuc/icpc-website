#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		cout << "Case " << tt << ": " << a[n/2] << endl;
	}
	return 0;
}

