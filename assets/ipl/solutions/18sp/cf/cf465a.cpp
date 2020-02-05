#include <iostream>

using namespace std;

int main () {
	int n; string s;
	cin >> n >> s;
	int ans = 0;
	for (; ans < n && s[ans] == '1'; ans++);
	if (ans == n) cout << ans << endl;
	else cout << ans + 1 << endl;
	return 0;
}

