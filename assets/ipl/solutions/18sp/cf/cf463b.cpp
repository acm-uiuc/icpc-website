#include <iostream>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ans = 0;
	while (n--) { int h; cin >> h; ans = max(ans, h); }
	cout << ans << endl;
	return 0;
}

