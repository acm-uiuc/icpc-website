#include <iostream>

using namespace std;

int ss[50], xx[50];

int main () {
	long long s, x;
	cin >> s >> x;
	long long _s = s, _x = x;
	for (int i = 0; i < 50; i++) {
		ss[i] = s & 1;
		s >>= 1;
		xx[i] = x & 1;
		x >>= 1;
	}
	long long ans = 1;
	int jin = 0;
	for (int i = 0; i < 49; i++) {
		if (ss[i] == 0 && xx[i] == 0) {
			if (jin == 0) { jin = ss[i+1] ^ xx[i+1]; }
			else { cout << 0 << endl; return 0; }
		}
		if (ss[i] == 0 && xx[i] == 1) {
			if (jin == 0) { cout << 0 << endl; return 0; }
			else { ans <<= 1; }
		}
		if (ss[i] == 1 && xx[i] == 0) {
			if (jin == 0) { cout << 0 << endl; return 0; }
			else { jin = ss[i+1] ^ xx[i+1]; }
		}
		if (ss[i] == 1 && xx[i] == 1) {
			if (jin == 0) { ans <<= 1; }
			else { cout << 0 << endl; return 0; }
		}
	}
	if (_s == _x) ans -= 2;
	cout << ans << endl;

	return 0;
}

