#include <iostream>
#include <algorithm>

using namespace std;

int f[1000];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> f[i];
    sort(f, f + m);

    int x = 9999;
    for (int i = 0; i + n <= m; ++i)
        x = min(x, f[i + n - 1] - f[i]);

    cout << x << endl;
    return 0;
}
