#include <iostream>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 3 == 0 || (n + 1) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

