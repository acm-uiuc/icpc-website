#include <iostream>

using namespace std;

bool a[10000];

int main () {
	int n;
	while (cin >> n) {
	int prev = 0;
	for (int i = 0; i < n; i ++) a[i] = 0;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (i) a[abs(x - prev)] = true;
		prev = x;
	}
	bool flag = true;
	for (int i = 1; i < n; i ++) flag &= a[i];
	if (flag) cout << "Jolly" << endl;
	else cout << "Not jolly" << endl;
	}
	return 0;
}

