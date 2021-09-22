#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200];
int color[200];

bool dfs (int u) {
    bool ans = true;
    for (int c : adj[u]) {
        if (color[c] == 0) {
            color[c] = 3 - color[u];
            ans = ans && dfs(c);
        } else if (color[c] == color[u]) {
            return false;
        }
    }
    return true;
}

int main () {
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            color[i] = 0;
        }
        int l; cin >> l;
        while (l--) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        color[0] = 1;
        bool ans = dfs(0);
        if (ans) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }

    return 0;
}

