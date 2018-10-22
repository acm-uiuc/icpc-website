#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main () {
	int n, m, d; cin >> n >> m >> d;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int ptr = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		while (a[i].first - a[ptr].first > d) ptr++;
		ans = max(ans, i - ptr + 1);
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++) b[a[i].second] = i % ans + 1;
	cout << ans << endl;
	for (int i = 0; i < n; i++) cout << b[i] << ' ';
	cout << endl;

	return 0;
}

