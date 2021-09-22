#include <iostream>
#include <vector>

using namespace std;



int main () {
    int n, m; cin >> n >> m;
    vector<int> a(101, 0);
    for (int i = 0; i < m; i++) {
        int ai; cin >> ai; a[ai]++;
    }
    for (int ans = 100; ans > 0; ans--) {
        int cnt = 0;
        for (int i : a) cnt += i / ans;
        if (cnt >= n) { cout << ans << endl; return 0; }
    }
    cout << 0 << endl;

    return 0;
}

