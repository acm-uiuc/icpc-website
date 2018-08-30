#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, s = 0; cin >> x;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        cout << s << endl;
    }
    return 0;
}
