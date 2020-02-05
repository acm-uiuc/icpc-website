#include <iostream>
#define LL long long

using namespace std;

int main () {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        LL a, b, c; cin >> a >> b >> c;
        cout << "Case " << tt << ": ";
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || b + c <= a || c + a <= b) cout << "Invalid" << endl;
        else if (a == b && b == c && c == a) cout << "Equilateral" << endl;
        else if (a == b || b == c || c == a) cout << "Isosceles" << endl;
        else cout << "Scalene" << endl;
    }
    
    return 0;
}

