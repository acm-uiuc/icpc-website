#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull div_ceil(ull a, ull b)
{
    return (a + b - 1) / b;
}

int main()
{
    int n; cin >> n;
    ull x, y;
    cin >> x >> y;
    for (int i = 1; i < n; ++i) {
        ull p, q;
        cin >> p >> q;
        ull n = max(div_ceil(x, p), div_ceil(y, q));
        x = n * p;
        y = n * q;
    }
    cout << x + y << endl;
    return 0;
}
