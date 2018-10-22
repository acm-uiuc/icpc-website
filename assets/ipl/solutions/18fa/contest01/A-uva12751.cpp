#include <iostream>
#define LL long long

using namespace std;



int main () {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        LL n, k, x;
        cin >> n >> k >> x;
        LL ans = n * (n + 1) / 2 - (2 * x + k - 1) * k / 2;
        cout << "Case " << tt << ": " << ans << endl;
    }

    return 0;
}

