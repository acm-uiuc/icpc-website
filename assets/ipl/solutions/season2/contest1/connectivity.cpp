#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <set>
#include <map>
 
using namespace std;
 
const int oo = 1e8, maxN = 2e5 + 10, modP = 1e9 + 7;
 
int c[maxN][2], n, k, m, q[maxN], flag;
vector < int > adj[maxN];
map < pair < int, int >, int > mmap;
 
void bfs(int u, int t) {
    int l = 1, r = 1;
    q[1] = u; 
    c[u][t] = ++flag;
    while (l <= r) {
        int u = q[l++];
        c[u][t] = flag;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (c[v][t]) continue;
            c[v][t] = flag;
            q[++r] = v;
        }
    }
}
 
int main() {
    cin >> n >> k >> m;
    for (int i = 1; i <= k; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for (int i = 1; i <= n; ++i)
        if (!c[i][0]) bfs(i, 0);
 
    flag = 0;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for (int i = 1; i <= n; ++i)
        if (!c[i][1]) bfs(i, 1);
 
    for (int i = 1; i <= n; ++i) mmap[make_pair(c[i][0], c[i][1])]++;
    for (int i = 1; i <= n; ++i) printf("%d ", mmap[make_pair(c[i][0], c[i][1])]);
}
