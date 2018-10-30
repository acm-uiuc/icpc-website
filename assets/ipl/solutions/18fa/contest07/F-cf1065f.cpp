#include <iostream>
#include <vector>
#define NMAX 1000001

using namespace std;

int n, k;
int p[NMAX];
vector<int> c[NMAX];
int dep[NMAX];
int dep2cnt[NMAX + NMAX];
int depkleafcnt[NMAX];
int depgekleafcnt[NMAX];
int cntleaf[NMAX];
int dp0[NMAX];  // must return
int dp1[NMAX];  // may not return

void dfs (int u, int d) {
	dep[u] = d;
	if (c[u].empty()) {
		dep2cnt[d] ++;
		cntleaf[u] = 1;
	}
	int tmp = dep2cnt[d+k];
	for (int v : c[u]) {
		dfs(v, d+1);
		depgekleafcnt[u] += depgekleafcnt[v];
		cntleaf[u] += cntleaf[v];
	}
	depkleafcnt[u] = dep2cnt[d+k] - tmp;
	depgekleafcnt[u] += depkleafcnt[u];
}

void work (int u) {
	for (int v : c[u]) {
		work(v);
	}
	/*
	int ans = cntleaf[u] - depgekleafcnt[u] + depkleafcnt[u];
	int delta = 0;
	for (int v : c[u]) {
		int d = dp[v] - (cntleaf[v] - depgekleafcnt[v]);
		delta = max(delta, d);
	}
	ans += delta;
	dp[u] = ans;
	*/
	if (c[u].empty()) {
		dp0[u] = dp1[u] = 1;
		return;
	}
	if (cntleaf[u] == depgekleafcnt[u]) {
		dp0[u] = 0;
	} else {
		for (int v : c[u]) {
			dp0[u] += dp0[v];
		}
	}

	for (int v : c[u]) {
		if (cntleaf[v] > depgekleafcnt[v]) {
			dp1[u] += dp0[v];
		}
	}
	int delta = 0;
	for (int v : c[u]) {
		delta = max(delta, dp1[v] - dp0[v]);
	}
	dp1[u] += delta;
}

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		c[p[i]].push_back(i);
	}
//	for (int i = 1; i <= n; i++) { cout << i << ": "; for (int v : c[i]) cout << v << ' '; cout << endl; }
	dfs(1, 0);
	work(1);
//	for (int i = 1; i <= n; i++) cout << i << ": " << cntleaf[i] << ' ' << depkleafcnt[i] << ' ' << depgekleafcnt[i] << ' ' << dp0[i] << ' ' << dp1[i] << endl;
	cout << dp1[1] << endl;

	return 0;
}

