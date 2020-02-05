#include <iostream>
#include <vector>
#define LL long long
#define MOD 1000000007

using namespace std;

int powplus1 (int p, int a) {
    LL ans = 1, base = p;
    while (a) {
        if (a & 1) ans = ans * base % MOD;
        base = base * base % MOD;
        a >>= 1;
    }
    ans = (ans + 1) % MOD;
    return (int)ans;
}

LL extended_euclid(LL p, LL q, LL &x, LL &y) {
    if (q == 0) {
        x = 1;
        y = 0;
        return p;
    }
    LL gcd = extended_euclid(q, p%q, y, x);
    y -= p / q * x;
    return gcd;
}

LL mod_linear_equation(LL a, LL b, LL n) {
    LL x, y;
    LL gcd = extended_euclid(a, n, x, y);
    if (b % gcd) return -1;
    x *= b / gcd;
    x %= n / gcd;
    if (x < 0) x += n / gcd;
    return x;
}

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, p;
    while (cin >> n >> p) {
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<LL> s(n+1);
        s[0] = 1;
        vector<int> zeros(n+1, 0);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i-1] * powplus1(p, a[i]) % MOD;
            zeros[i] = zeros[i-1];
            if (s[i] == 0) {
                s[i] = 1;
                zeros[i]++;
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (zeros[r] != zeros[l-1]) {
                cout << MOD - 1 << endl;
                continue;
            }
            LL inv = mod_linear_equation(s[l-1], 1, MOD);
            LL ans = inv * s[r] % MOD;
            ans = (ans + MOD - 1) % MOD;
            cout << ans << endl;
        }
    }

    return 0;
}

