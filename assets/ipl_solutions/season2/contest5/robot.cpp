#include <cstdio>

#define MOD 1000000007
#define MAX 5010

int N, K;
long long fact[MAX];
long long inv_fact[MAX]; 

inline long long mul(long long a, long long b) {
    return a * b % MOD;
}

long long pow(long long n, long long p) {
    if (p == 0)
        return 1;
    long long res = pow(n, p >> 1);
    res = mul(res, res);
    if (p & 1) 
        res = mul(res, n);
    return res;
}

long long binom(long long n, long long k) {
    return mul(mul(fact[n], inv_fact[k]), inv_fact[n - k]);
}

void build() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv_fact[i] = pow(fact[i], MOD - 2);
    }
}

int main() {
    build();
    while (scanf("%d %d", &N, &K) == 2 && N && K) {
        long long res = 0;
        K++;
        int down = (K >> 1) - 1, right = K - (K >> 1) - 1;
        res = mul(binom(N - 2, down), binom(N - 2, right));
        res = mul(res, 2);
        printf("%lld\n", res);
    }
    return 0;
}
