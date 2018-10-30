#include <iostream>

using namespace std;

int main () {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int ans1 = (n / m) * b + (n % m) * a;  // mixed
	int ans2 = ((n + m - 1) / m) * b;  // all multiple
	int ans3 = n * a;  // all single
	cout << min(min(ans1, ans2), ans3) << endl;
	return 0;
}

