#include <iostream>
#include <cmath>

using namespace std;


int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = (n * 567 / 9 + 7492) * 235 / 47 - 498;
        ans = abs(ans) / 10 % 10;
        cout << ans << endl;
    }

    return 0;
}

