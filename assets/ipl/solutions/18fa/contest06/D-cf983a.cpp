#include <iostream>
#define LL long long

using namespace std;

LL gcd (LL p, LL q) { return q == 0 ? p : gcd(q, p%q); }

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		LL p, q, b;
		cin >> p >> q >> b;
		LL g = gcd(p, q);
		p /= g; q /= g;
		while (true) {
			LL g = gcd(b, q);
			if (g == 1) break;
			while (q % g == 0) q /= g;
		}
		if (q == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}

	return 0;
}

