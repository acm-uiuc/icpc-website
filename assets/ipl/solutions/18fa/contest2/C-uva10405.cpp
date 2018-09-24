#include <iostream>
#include <vector>

using namespace std;

int main () {
	string s, t;
	while (1) {
		getline(cin, s);
		getline(cin, t);
		if (!cin) break;
		vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, 0));
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < t.length(); j++) {
				if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
				else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
		cout << dp[s.length()][t.length()] << endl;
	}
	
	return 0;
}

