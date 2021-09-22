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
#include <unordered_map>

const int maxN = 11;

using namespace std;

int f[1 << maxN][1 << maxN], n, m, c[maxN][maxN], k, res;

int dp(int connected, int leaves) {
    if (__builtin_popcount(connected) == 2) {
        int u = 0, v = 0;
        for (int i = 0; i < n; ++i)
            if ((connected >> i) & 1) {
                if (!u) u = i;
                else v = i;
            }
        return (connected == leaves && c[u][v]);
    }
    if (__builtin_popcount(leaves) < 2) return 0;
    if (f[connected][leaves] != -1) return f[connected][leaves];

    int u = 0;
    for (int i = 0; i < n; ++i)
        if ((leaves >> i) & 1) {
            u = i;
            break;
        }

    f[connected][leaves] = 0;
    for (int v = 0; v < n; ++v)
        if (c[u][v] && !((leaves >> v) & 1) && ((connected >> v) & 1))
            f[connected][leaves] += (
                dp(connected ^ (1 << u), leaves ^ (1 << u)) +
                dp(connected ^ (1 << u), leaves ^ (1 << u) ^ (1 << v)));

    return f[connected][leaves];
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        c[u][v] = c[v][u] = 1;
    }

    memset(f, 255, sizeof(f));
    for (int i = 0; i < (1 << n); ++i)
        if (__builtin_popcount(i) == k)
            res += dp((1 << n) - 1, i);

    cout << res;
}
