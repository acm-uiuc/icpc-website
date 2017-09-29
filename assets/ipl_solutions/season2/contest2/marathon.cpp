#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double orig_a, orig_d;
    scanf("%lf %lf", &orig_a, &orig_d);

    long long a = round(orig_a * 1e4), d = round(orig_d * 1e4), n;
    scanf("%lld", &n);
    
    for (int i = 1; i <= n; i++) {
        long long rem = d * i % (4 * a);

        if (rem < a) 
            printf("%f %f\n", rem / 1e4, 0.0);
        else if (rem < 2 * a)
            printf("%f %f\n", a / 1e4, (rem - a) / 1e4);
        else if (rem < 3 * a)
            printf("%f %f\n", (a - (rem - 2 * a)) / 1e4, a / 1e4);
        else
            printf("%f %f\n", 0.0, (a - (rem - 3 * a)) / 1e4);
    }
}
