#include <iostream>
#include <stack>

using namespace std;

int main () {
	int n;
	cin >> n;
	int speed;
	int ignore = 0;
	stack<int> speed_limits;
	int overtake_limits = 0;
	while (n--) {
		int t;
		cin >> t;
		switch (t) {
		case 1:
			cin >> speed;
			while (!speed_limits.empty() && speed > speed_limits.top()) {
				speed_limits.pop();
				ignore ++;
			}
			break;
		case 2:
			ignore += overtake_limits;
			overtake_limits = 0;
			break;
		case 3:
			int speed_limit;
			cin >> speed_limit;
			speed_limits.push(speed_limit);
			while (!speed_limits.empty() && speed > speed_limits.top()) {
				speed_limits.pop();
				ignore ++;
			}
			break;
		case 4:
			overtake_limits = 0;
			break;
		case 5:
			while (!speed_limits.empty()) speed_limits.pop();
			break;
		case 6:
			overtake_limits ++;
			break;
		}
	}
	cout << ignore << endl;
	return 0;
}

