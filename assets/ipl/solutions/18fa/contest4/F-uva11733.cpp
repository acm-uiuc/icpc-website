#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[10001];
vector<pair<int,pair<int,int>>> e;
int n, m, a;

int find (int u) {
    return p[u] < 0 ? u : (p[u] = find(p[u]));
}

void unione (int u, int v) {
    u = find(u);
    v = find(v);
    if (p[u] < p[v]) {
        p[u] += p[v];
        p[v] = u;
    } else {
        p[v] += p[u];
        p[u] = v;
    }
}

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        for (int i = 1; i <= 10000; i++) {
            p[i] = -1;
        }
        e.clear();
        cin >> n >> m >> a;
        while (m--) {
            int x, y, c;
            cin >> x >> y >> c;
            e.push_back({c, {x, y}});
        }
        sort(e.begin(), e.end());
        int cost = 0, road = 0;
        for (auto ee : e) {
            int c = ee.first;
            int x = ee.second.first, y = ee.second.second;
            if (c >= a) break;
            if (find(x) == find(y)) continue;
            unione(x, y);
            cost += c;
            road ++;
        }
        int airp = n - road;
        cost += a * airp;
        printf("Case #%d: %d %d\n", tt, cost, airp);
    }
    
    return 0;
}

