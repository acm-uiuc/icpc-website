#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main () {
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	bool a[26][26];
	for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) a[i][j] = 0;
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a'][t[i] - 'a'] = a[t[i] - 'a'][s[i] - 'a'] = 1;
	}
	bool vis[26];
	for (int i = 0; i < 26; i++) vis[i] = 0;
	vector<pair<int,int> > ans;
	for (int i = 0; i < 26; i++) {
		if (!vis[i]) {
			vector<int> rea;
			queue<int> q; q.push(i); vis[i] = 1;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int v = 0; v < 26; v++) if (a[u][v] && !vis[v]) {
					vis[v] = 1;
					q.push(v);
					rea.push_back(v);
				}
			}
			for (int v : rea) ans.push_back({i, v});
		}
	}
	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << char('a' + p.first) << ' ' << char('a' + p.second) << endl;
	}
	return 0;
}

