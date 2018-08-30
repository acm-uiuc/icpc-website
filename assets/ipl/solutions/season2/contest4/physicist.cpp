#include <iostream>

using namespace std;

int main () {
	int n;
	cin >> n;
	int sumx = 0, sumy = 0, sumz = 0;
	while (n--) {
		int x, y, z;
		cin >> x >> y >> z;
		sumx += x;
		sumy += y;
		sumz += z;
	}
	if (sumx || sumy || sumz) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}

