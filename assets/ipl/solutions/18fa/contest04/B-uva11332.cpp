#include <iostream>

using namespace std;

int f (int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int g (int x) {
    while (x >= 10) {
        x = f(x);
    }
    return x;
}

int main () {
    int x;
    while (cin >> x && x) {
        cout << g(x) << endl;
    }
    return 0;
}

