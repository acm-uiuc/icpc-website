#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int mex (set<int> suc) {
    for (int i = 0; ; i++) {
        if (suc.find(i) == suc.end()) {
            return i;
        }
    }
}

int main () {
    int n; cin >> n;
    vector<int> sg(n+1, 0);
    int ans = -1;
    for (int x = 3; x <= n; x++) {
        set<int> suc;
        for (int m = 2; m * (m+1) / 2 <= x; m++) {
            int r = x - m * (m+1) / 2;
            if (r % m) continue;
            int a = r / m + 1;
            int xor_sum = 0;
            for (int j = 0; j < m; j++) xor_sum ^= sg[a + j];
            suc.insert(xor_sum);
            if (x == n && xor_sum == 0 && ans == -1) ans = m;
        }
        sg[x] = mex(suc);
    }
    cout << ans << endl;

    return 0;
}

