#include <iostream>
#include <string>

using namespace std;

int main () {
	string s;
	int k;
	cin >> s >> k;
	bool exist[26];
	for (int i = 0; i < 26; i ++) exist[i] = false;
	for (char c : s) exist[c - 'a'] = true;
	int cnt = 0;
	for (int i = 0; i < 26; i ++) cnt += exist[i];
	if (cnt >= k) cout << 0 << endl;
	else if (k <= s.length()) cout << k - cnt << endl;
	else cout << "impossible" << endl;
	return 0;
}

