#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char c[20][20];
int x, y;  // current coordinate
char land, water = 0;

// bfs from one cell, mark all reachable cells, and return size
int bfs (int x, int y) {
	int cnt = 0;
	queue<pair<int,int> > q;
	if (c[x][y] == land) { q.push({x,y}); c[x][y] = water; }
	while (!q.empty()) {
		pair<int,int> p = q.front(); q.pop(); cnt++;
		int x = p.first, y = p.second;
		if (x>0 && c[(x+n-1)%n][y] == land) {c[(x+n-1)%n][y] = water; q.push({(x+n-1)%n,y}); }
		if (x<n-1 && c[(x+1)%n][y] == land) {c[(x+1)%n][y] = water; q.push({(x+1)%n,y}); }
		if (c[x][(y+m-1)%m] == land) {c[x][(y+m-1)%m] = water; q.push({x,(y+m-1)%m}); }
		if (c[x][(y+1)%m] == land) {c[x][(y+1)%m] = water; q.push({x,(y+1)%m}); }
	}
	return cnt;
}

int main () {
while (scanf("%d %d", &n, &m) != EOF) {
	for (int i = 0; i < n; i++) {
		char s[30];
		scanf("%s", s);
		for (int j = 0; j < m; j++) c[i][j] = s[j];
	}
	scanf("%d %d", &x, &y);
	land = c[x][y];
	bfs(x, y);  // exclude his own land
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, bfs(i, j));
		}
	}
	printf("%d\n", ans);
}

	return 0;
}

