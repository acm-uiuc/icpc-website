#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
    vector<int> stairs(n);
    stairs[0] = 1;
    stairs[1] = 2;
    for (int i = 2; i < n; i++) {
        stairs[i] = stairs[i - 1] + stairs[i - 2];
    }
    return stairs[n - 1];
    }
}

int main() {
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}
