#include <iostream>
#define LL long long
#define MOD 1000000007

using namespace std;

struct Matrix {
	int n = 2;
	LL a[2][2];

	Matrix () {
		a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
	}
	Matrix (int A, int B) {
		a[0][0] = A;
		a[0][1] = B;
		a[1][0] = 0;
		a[1][1] = 1;
	}

	Matrix operator* (const Matrix &b) const {
		Matrix ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					ans.a[i][j] += a[i][k] * b.a[k][j];
					ans.a[i][j] %= MOD;
				}
			}
		}
		return ans;
	}

	Matrix operator^ (LL n) const {
		Matrix ans;
		ans.a[0][0] = ans.a[1][1] = 1;
		Matrix base = *this;
		while (n) {
			if (n & 1) ans = ans * base;
			base = base * base;
			n >>= 1;
		}
		return ans;
	}
};

int main () {
	int A, B, x; LL n;
	cin >> A >> B >> n >> x;
	Matrix m(A, B);
	Matrix mm = m ^ n;
	LL ans = (mm.a[0][0] * x + mm.a[0][1]) % MOD;
	cout << ans << endl;

	return 0;
}

