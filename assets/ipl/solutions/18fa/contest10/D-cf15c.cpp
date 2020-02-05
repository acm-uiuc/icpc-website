#include <iostream>
#define LL long long

using namespace std;

// computes XOR sum of 1..n
LL work (LL n) {
    LL ans = 0;
    if (n % 2 == 0) { ans = n; n--; }
    if ((n+1) % 4) ans ^= 1;
    return ans;
}

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    LL ans = 0;
    int n; cin >> n;
    while (n--) {
        LL x, m; cin >> x >> m;
        ans ^= work(x + m - 1) ^ work(x - 1);
    }
    if (ans) cout << "tolik" << endl;
    else cout << "bolik" << endl;

    return 0;
}

