#include <iostream>
#include <cstdio>

using namespace std;

int main () {
	int n, m;  // n 0's and m 1's
	cin >> n >> m;
	if (m < n-1 || m > 2*(n+1)) {
		cout << -1 << endl;
		return 0;
	}
	if (m < n) {
		printf("0");
		n --;
	}
	while (n) {
		if (m > n) {
			printf("110");
			m -= 2;
			n -= 1;
		} else {
			printf("10");
			m -= 1;
			n -= 1;
		}
	}
	while (m) {
		printf("1");
		m --;
	}
	cout << endl;

	return 0;
}

