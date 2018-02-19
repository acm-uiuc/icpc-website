#include <iostream>

using namespace std;

int main () {
	int K;
	while (1) {
		cin >> K;
		if (K == 0) break;
		int x0, y0;
		cin >> x0 >> y0;
		while (K--) {
			int x, y;
			cin >> x >> y;
			if (x == x0 || y == y0) cout << "divisa" << endl;
			else if (x < x0 && y < y0) cout << "SO" << endl;
			else if (x < x0 && y > y0) cout << "NO" << endl;
			else if (x > x0 && y < y0) cout << "SE" << endl;
			else if (x > x0 && y > y0) cout << "NE" << endl;
		}
	}
	return 0;
}

