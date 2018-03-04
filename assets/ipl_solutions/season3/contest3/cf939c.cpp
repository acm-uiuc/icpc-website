#include <iostream>
#include <vector>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int s, f;
	cin >> s >> f;
	int ans = 0;
	int real_ans = n;
	int sum = 0, best = 0;
	for (int i = 0; i < f-s; i++) sum += a[i];
	for (int pos = 0; pos < n; pos++) {
		sum -= a[pos]; sum += a[(pos + (f-s)) % n];
		if (sum > best) { best = sum; ans = pos + 1; real_ans = (s - ans + n - 1) % n + 1; }
		else if (sum == best) { int new_real_ans = (s - (pos + 1) + n - 1) % n + 1; if (new_real_ans < real_ans) { real_ans = new_real_ans; ans = pos + 1; }}
	}
	// in time zone ans+1 the start time is s
	cout << real_ans << endl;

	return 0;
}

