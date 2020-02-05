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

const long long oo = 1000000000000000000ll;
const int maxN = 1e6 + 10;

using namespace std;

int n, a[maxN], A, B;
set < int > factor_set;
long long res, f[maxN][3];

int price(int x, int d) {
    if (x % d == 0) return 0;
    if (x % d == 1 || x % d == d - 1) return B;
    return -1;
}

void factorize(int x) {
    for (int i = 2; i <= (int) sqrt(x); ++i)
        if (x % i == 0) {
            factor_set.insert(i);
            while (x % i == 0) x /= i;
        }
    if (x != 1) factor_set.insert(x);
}

int main() {
    scanf("%d %d %d", &n, &A, &B);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    if (n == 1) {
        cout << 0;
        return 0;
    }

    for (int i = -1; i <= 1; ++i) {
        factorize(a[1] + i);
        factorize(a[n] + i);
    }

    res = oo;
    for (auto d : factor_set) {
        for (int i = 1; i <= n; ++i) {
            f[i][0] = f[i][1] = f[i][2] = oo;
            if (price(a[i], d) != -1) {
                f[i][0] = f[i - 1][0] + price(a[i], d);
                f[i][2] = min(f[i - 1][2], f[i - 1][1]) + price(a[i], d);
            }
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + A;
        }
        long long tmp = min(f[n][1], min(f[n][2], f[n][0]));
        res = min(res, tmp);
    }

    cout << res;
}
