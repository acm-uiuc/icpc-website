#include <iostream>

using namespace std;

int main () {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n; cin >> n;
        int mile = 0, juice = 0;
        while (n--) {
            int x; cin >> x;
            mile += (x / 30 + 1) * 10;
            juice += (x / 60 + 1) * 15;
        }
        cout << "Case " << tt << ": ";
        if (mile < juice) cout << "Mile " << mile << endl;
        else if (mile > juice) cout << "Juice " << juice << endl;
        else cout << "Mile Juice " << mile << endl;
    }

    return 0;
}

