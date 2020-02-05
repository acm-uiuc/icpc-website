#include <iostream>
#include <string>

using namespace std;

string s[50];

string rotate(const string & s, int n) {
    return s.substr(n) + s.substr(0, n);
}

static const int inf = 1000000;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    int m = s[0].size(), ans = inf;
    for (int i = 0; i < m; ++i) {
        int t = 0;
        for (int j = 1; j < n; ++j) {
            int r = inf;
            for (int k = 0; k < m; ++k)
                if (rotate(s[0], i) == rotate(s[j], k)) {
                    r = k;
                    break;
                }
            t += r;
        }
        ans = min(ans, i + t);
    }
    if (ans < inf)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
