#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

const int maxN = 1e5 + 10;

using namespace std;

int n, deg[maxN], parent[maxN], k;
stack < int > s[maxN];

struct vertex {
    vertex(int new_v, int new_d) {
        v = new_v;
        d = new_d;
    }

    int v, d;
};

vector < vertex > vertices;

bool cmp(vertex i, vertex j) {
    return i.d < j.d;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int d; scanf("%d", &d);
        vertices.push_back(vertex(i, d));
    }

    sort(vertices.begin(), vertices.end(), cmp);
    if (vertices[0].d) {
        cout << -1;
        return 0;
    }
    s[0].push(vertices[0].v);
    for (int i = 1; i < n; ++i) {
        if (vertices[i].d <= 0 || s[vertices[i].d - 1].empty()) {
            cout << -1;
            return 0;
        }
        int v = vertices[i].v;
        int u = s[vertices[i].d - 1].top();
        ++deg[u];
        ++deg[v];
        parent[v] = u;
        if (deg[u] == k) 
            s[vertices[i].d - 1].pop();
        s[vertices[i].d].push(v);
    }

    cout << n - 1 << endl;
    for (int i = 1; i <= n; ++i)
        if (parent[i]) printf("%d %d\n", i, parent[i]);
}
