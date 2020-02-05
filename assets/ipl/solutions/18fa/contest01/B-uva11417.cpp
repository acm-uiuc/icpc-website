#include <iostream>

using namespace std;

int gcd (int p, int q) {
    return q == 0 ? p : gcd(q, p%q);
}

int main () {
    int n;
    while (cin >> n && n != 0) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                ans += gcd(i, j);
            }
        }
        cout << ans << endl;
    }

    return 0;
}

