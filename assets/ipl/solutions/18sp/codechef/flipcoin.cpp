#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

const int maxN = 1e5 + 10;

int t[4 * maxN], g[4 * maxN], n, q;

int get_head(int k, int l, int r) {
    return (g[k] ? (r - l + 1) - t[k] : t[k]);
}

void lazy_update(int k, int l, int r) {
    if (l != r) {
        g[k * 2] ^= g[k];
        g[k * 2 + 1] ^= g[k];
        g[k] = 0;
        int mid = (l + r) >> 1;
        t[k] = get_head(k * 2, l, mid) + 
               get_head(k * 2 + 1, mid + 1, r);
        return;
    }
    t[k] = g[k] ^ t[k];
    g[k] = 0;
}

void update(int k, int l, int r, int i, int j) {
    if (j < l || r < i) return;
    lazy_update(k, l, r);
    if (i <= l && r <= j) {
        g[k] ^= 1;
        return;
    }
    int mid = (l + r) >> 1;
    update(k * 2, l, mid, i, j);
    update(k * 2 + 1, mid + 1, r, i, j);
    t[k] = get_head(k * 2, l, mid) + 
           get_head(k * 2 + 1, mid + 1, r);
}

int get(int k, int l, int r, int i, int j) {
    if (j < l || r < i) return 0;
    lazy_update(k, l, r);
    if (i <= l && r <= j) return t[k];
    int mid = (l + r) >> 1;
    return get(k * 2, l, mid, i, j) +
           get(k * 2 + 1, mid + 1, r, i, j);
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int t, l, r; 
        cin >> t >> l >> r;
        ++l; ++r;
        if (t == 0)
            update(1, 1, n, l, r);
        else
            cout << get(1, 1, n, l, r) << endl;
    }
}
