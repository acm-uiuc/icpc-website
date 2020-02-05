#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int maxN = 1e5 + 10;
const double PI = acos(-1);

int n, res, m, deg[maxN], num_comp, cnt_comp[maxN], comp[maxN], num[maxN], low[maxN], k, avail[maxN], num_node;
vector < int > adj[maxN];
stack < int > s;

void visit(int u) {
    low[u] = num[u] = ++num_node;
    s.push(u);
    for (int i = 0; i < adj[i].size(); ++i) {
        int v = adj[u][i];
        if (avail[v]) continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        ++num_comp;
        int v = 0;
        while (v != u) {
            v = s.top(); s.pop();
            avail[v] = 1; 
            comp[v] = num_comp;
            ++cnt_comp[num_comp];
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!num[i]) visit(i);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < adj[i].size(); ++j) {
            int u = comp[i];
            int v = comp[adj[i][j]];
            if (u == v) continue;
            ++deg[u];
        }

    res = -1;
    for (int i = 1; i <= num_comp; ++i)
        if (deg[i] == 0) 
            if (res == -1 || cnt_comp[i] * k < res)
                res = cnt_comp[i] * k;
    cout << res << endl;
}
