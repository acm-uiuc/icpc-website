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

using namespace std;

const int maxN = 1e5 + 10;

int tL[maxN * 4], tR[maxN * 4], tM[maxN * 4], a[maxN], n, q;

void update(int k, int l, int r, int i, int v) {
    if (i < l || r < i) return;
    if (l == r) {
        tL[k] = tR[k] = tM[k] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(k * 2, l, mid, i, v);
    update(k * 2 + 1, mid + 1, r, i, v);
    tL[k] = (tL[k * 2] == mid - l + 1) ? tL[k * 2] + tL[k * 2 + 1] : tL[k * 2];
    tR[k] = (tR[k * 2 + 1] == r - mid) ? tR[k * 2 + 1] + tR[k * 2] : tR[k * 2 + 1];
    tM[k] = max(tM[k * 2], tM[k * 2 + 1]);
    tM[k] = max(tM[k], max(tL[k], tR[k]));
    tM[k] = max(tM[k], tR[k * 2] + tL[k * 2 + 1]);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i)
        update(1, 1, n - 1, i, (a[i + 1] - a[i]) == 1);

    cout << tM[1] + 1 << endl;

    for (int i = 1; i <= q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x] = y;
        if (x != n)
            update(1, 1, n - 1, x, (a[x + 1] - a[x]) == 1);
        if (x != 1)
            update(1, 1, n - 1, x - 1, (a[x] - a[x - 1]) == 1);
        printf("%d\n", tM[1] + 1);
    }
}
