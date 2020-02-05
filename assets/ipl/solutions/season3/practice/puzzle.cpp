#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 1e3 + 10;

int a[maxN], m, n, res;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &a[i]);
    sort(a, a + m);
    res = 1e9;
    for (int i = n - 1; i < m; ++i)
        res = min(res, a[i] - a[i - n + 1]);
    cout << res << endl;
}
