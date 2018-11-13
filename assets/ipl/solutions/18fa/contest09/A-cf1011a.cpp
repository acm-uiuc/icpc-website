#include <iostream>
#include <vector>

using namespace std;



int main () {
    int n, k; cin >> n >> k;
    bool a[27];
    for (int i = 1; i <= 26; i++) a[i] = false;
    string s; cin >> s;
    for (char c : s) a[c - 'a' + 1] = true;
    int prev = -1, ans = 0, cnt = 0;
    for (int i = 1; i <= 26; i++) {
        if (i - prev < 2 || !a[i]) continue;
        ans += i; cnt++; prev = i;
        if (cnt == k) break;
    }
    if (cnt == k) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}

