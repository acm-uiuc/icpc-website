#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) ans += max(l[i], r[i]);
	ans += n;
	cout << ans << endl;
	return 0;
}

