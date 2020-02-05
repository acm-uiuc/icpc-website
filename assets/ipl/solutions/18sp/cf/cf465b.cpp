#include <iostream>

using namespace std;

int main () {
	int n;
	cin >> n;
	bool nonzero = false;
	int nonzero_cnt = 0, seg_cnt = 0;
	while (n--) {
		int x; cin >> x;
		if (x) {
			if (nonzero == false) seg_cnt ++;
			nonzero = true;
			nonzero_cnt ++;
		} else {
			nonzero = false;
		}
	}
	if (seg_cnt == 0) cout << 0 << endl;
	else cout << nonzero_cnt + seg_cnt - 1 << endl;
	return 0;
}

