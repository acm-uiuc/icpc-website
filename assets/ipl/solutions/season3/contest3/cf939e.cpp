#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
#define LL long long

using namespace std;

int main () {
	int q;
	cin >> q;
	vector<int> a;
	int cnt = 0; LL sum = 0;
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int x; scanf("%d", &x);
			while (cnt < a.size()) {
				if ((sum + x) > (LL)a[cnt] * (cnt + 1)) {
					sum += a[cnt++];
				} else break;
			}
			a.push_back(x);
		} else {
			printf("%.8lf\n", a[a.size()-1] - (double) (sum + a[a.size()-1]) / (cnt + 1));
		}
	}


	return 0;
}

