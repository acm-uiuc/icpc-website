#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	while (1) {
		cin >> n;
		if (!n) break;
		set<int> exist;
		while (1) {
			if (exist.find(n) != exist.end()) break;
			exist.insert(n);
			n = n * n / 100 % 10000;
		}
		cout << exist.size() << endl;
	}
	return 0;
}

