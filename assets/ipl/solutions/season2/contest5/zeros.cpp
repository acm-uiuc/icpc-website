#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long remove_zeros(long x) {
    long y = 0, p = 1;
    while (x != 0) {
        long r = x % 10;
        if (r != 0) {
            y += r * p;
            p *= 10;
        }
        x /= 10;
    }
    return y;
}

int main()
{
    long a, b;
    cin >> a >> b;

    if (remove_zeros(a + b) == remove_zeros(a) + remove_zeros(b))
       cout << "YES" << endl;
    else
       cout << "NO" << endl; 

    return 0;
}
