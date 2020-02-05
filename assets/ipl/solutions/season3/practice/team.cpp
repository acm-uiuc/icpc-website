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

const int maxN = 5e6 + 10;

using namespace std;

int n, m, f[maxN];

int main() {
    cin >> n >> m;
    if ((n + 1) * 2 < m || m < n - 1) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n + 2 * (n + 1); ++i) 
        f[i] = -1;
    for (int i = 3; i <= 3 * n + 2; i += 3) {
        f[i] = 0;
        if (m)
            f[i + 1] = 1, --m;
    }
    for (int i = 1; i <= 3 * n + 2; ++i) {
        if (!m) break;
        if (f[i] == -1) f[i] = 1, --m;
    }
    for (int i = 1; i <= 3 * n + 2; ++i)
        if (f[i] >= 0)
            printf("%d", f[i]);
}
