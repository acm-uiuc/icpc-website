#include <iostream>

using namespace std;

int n, k;
int ans = 0;

int SG (int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (k % 2 == 0) {
        if (x == 2) return 2;
        if (x % 2 == 0) return 1;
        return 0;
    } else {
        if (x == 2) return 0;
        if (x == 3) return 1;
        if (x == 4) return 2;
        if (x % 2 == 1) return 0;
        return SG(x / 2) == 1 ? 2 : 1;
    }
}

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ans ^= SG(x);
    }
    if (ans) cout << "Kevin" << endl;
    else cout << "Nicky" << endl;

    return 0;
}

