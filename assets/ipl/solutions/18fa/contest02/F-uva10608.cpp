#include <iostream>

using namespace std;

int n, m;
int p[30000];

int find (int u) {
	return p[u] < 0 ? u : (p[u] = find(p[u]));
}
void unione (int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (p[u] < p[v]) {
		p[u] += p[v];
		p[v] = u;
	} else {
		p[v] += p[u];
		p[u] = v;
	}
}

int main () {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) p[i] = -1;
		while (m--) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			unione(u, v);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, -p[find(i)]);
		}
		cout << ans << endl;
	}

	return 0;
}

