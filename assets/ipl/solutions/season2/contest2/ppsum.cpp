#include <iostream>

using namespace std;

int sum (int D, int N) {
	if (D == 1) return N*(N+1)/2;
	return sum(1, sum(D-1, N));
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int D, N;
		cin >> D >> N;
		cout << sum(D, N) << endl;
	}
	return 0;
}

