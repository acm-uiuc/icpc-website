#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		int maxx = 0;
		while (n--) { int x; cin >> x; maxx = max(maxx, x); }
		cout << "Case " << i << ": " << maxx << endl;
	}
	return 0;
}

