#include <iostream>

using namespace std;

int main () {
	int twenty_five = 0, fifty = 0;  // keep track of 25 and 50 bills
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a == 25) {
			twenty_five ++;
		} else if (a == 50) {
			if (twenty_five == 0) {
				cout << "NO" << endl;
				return 0;
			}
			twenty_five --;
			fifty ++;
		} else {  // a == 100
			if (fifty && twenty_five) {  // give 50+25 is always better than 25+25+25
				fifty --;
				twenty_five --;
			} else if (twenty_five >= 3) {
				twenty_five -= 3;
			} else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}

