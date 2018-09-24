#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



int main () {
	int n;
	while (cin >> n && n) {
		double m = 1.6 * n;
		double ans = abs(round(m) - m);
		cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
	}

	return 0;
}

