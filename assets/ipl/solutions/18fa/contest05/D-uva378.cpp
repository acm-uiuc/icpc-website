#include <iostream>
#include <iomanip>

using namespace std;

int main () {
	int t; cin >> t;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while (t--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		if ((x3 - x1) * (y3 - y2) == (y3 - y1) * (x3 - x2) && (x4 - x1) * (y4 - y2) == (y4 - y1) * (x4 - x2)) {
			cout << "LINE" << endl;
		} else if ((x4 - x3) * (y2 - y1) == (y4 - y3) * (x2 - x1)) {
			cout << "NONE" << endl;
		} else {
			double a1 = y2 - y1, b1 = x1 - x2, c1 = x2 * y1 - x1 * y2;
			double a2 = y4 - y3, b2 = x3 - x4, c2 = x4 * y3 - x3 * y4;
			double x = -(c1 * b2 - b1 * c2) / (a1 * b2 - b1 * a2);
			double y = -(c1 * a2 - a1 * c2) / (b1 * a2 - a1 * b2);
			cout << setiosflags(ios::fixed) << setprecision(2) << "POINT " << x << ' ' << y << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}

