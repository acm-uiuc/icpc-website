#include <iostream>


using namespace std;

int comp(string s, string t) {
	for (auto &c : s) c = toupper(c);
	for (auto &c : t) c = toupper(c);
	if (s < t) return -1;
	if (s > t) return 1;
	return 0;
}

int main () {
	string s, t;
	cin >> s >> t;
	cout << comp(s, t) << endl;

	return 0;
}

