#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    long long Q, u, v, n;
    scanf("%lld", &Q);
    while (Q--) {
        scanf("%lld %lld %lld", &n, &u, &v);
        if (u > v)
            swap(u, v);

        while (u != v) {
            if (v > u) {
                if (v % 2 == 1) {
                    if (n % 2 == 0)
                        n -= 1;
                }
                else {
                    if (n % 2 == 1)
                        n -= 1;
                }
                v >>= 1;
                n >>= 1;
            }
            else {
                u >>= 1;
            }
        }
        printf("%lld\n", n);
    }
    return 0;
}
