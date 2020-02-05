#include <iostream>

using namespace std;

int main()
{
    int odd = 0, even = 0, sum = 0, n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        sum += x;
        if (x % 2 == 1)
            ++odd;
        else
            ++even;
    }

    cout << ((sum % 2 == 1) ? odd : even) << endl;
    return 0;
}
